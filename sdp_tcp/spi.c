#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stm32f4xx_spi.h>
#include <stm32f4xx_gpio.h>
#include <stm32f4xx_rcc.h>
#include "enc28j60.h"
void spi_test (void);
static int enc28j60CheckLinkState(void);

void spi1_configuration(void)
{
    SPI_InitTypeDef  SPI_InitStruct = {0};
    // enable peripheral clock
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1, ENABLE);

    SPI_DeInit(SPI1);
    SPI_InitStruct.SPI_Mode = SPI_Mode_Master; 
    SPI_InitStruct.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
    SPI_InitStruct.SPI_DataSize = SPI_DataSize_8b;
    SPI_InitStruct.SPI_CPOL = SPI_CPOL_Low;
    SPI_InitStruct.SPI_CPHA = SPI_CPHA_1Edge;
    SPI_InitStruct.SPI_NSS = SPI_NSS_Soft;
    SPI_InitStruct.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_64;
    SPI_InitStruct.SPI_FirstBit = SPI_FirstBit_MSB;
    SPI_InitStruct.SPI_CRCPolynomial = 7;
    SPI_Init(SPI1, &SPI_InitStruct);

    /* Enable SPI1  */
    SPI_Cmd(SPI1, ENABLE); 
    puts("Configure and Enable SPI1\r\n");
}

static const unsigned char enc28j60_MAC[6] = {0x11, 0x02, 0x03, 0x04, 0x05, 0x33};
int device_init(void)
{
    int ret = 1;
    ret = enc28j60Init((unsigned char *)enc28j60_MAC);
    if (ret) 
        printf("enc28j60Init failure (%d)...\r\n", ret);

    unsigned char rev = enc28j60getrev();
    printf("enc28j60 revsion: 0x%x\r\n", rev);
    enc28j60CheckLinkState();
    return ret;
}

void init_spi1(void)
{
    RCC_ClocksTypeDef RCC_Clocks;
    /* SysTick end of count event each 1ms */
    RCC_GetClocksFreq(&RCC_Clocks);
    //SysTick_Config(RCC_Clocks.SYSCLK_Frequency / 1000);;
    printf("sysclk: %d MHz\r\n", RCC_Clocks.SYSCLK_Frequency / 1000000);

    GPIO_InitTypeDef GPIO_InitStruct = {0};

    /* Enable SPI1 and GPIOA clocks */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1, ENABLE);

    /* Configure SPI1 pins:  
     * PA5 = SCK
     * PA6 = MISO
     * PA7 = MOSI */
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_25MHz;
    GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_DOWN;
    GPIO_Init(GPIOA, &GPIO_InitStruct);
    puts("Enable SPI1 and GPIOA Clocks\r\n");

    // connect SPI1 pins to SPI alternate function
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource5, GPIO_AF_SPI1);
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource6, GPIO_AF_SPI1);
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource7, GPIO_AF_SPI1);

#if 0
    /* SPI SCK pin configuration */
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_5;
    GPIO_Init(GPIOA, &GPIO_InitStruct);

    /* SPI MISO pin configuration */
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_6;
    GPIO_Init(GPIOA, &GPIO_InitStruct);

    /* SPI  MOSI pin configuration */
    GPIO_InitStruct.GPIO_Pin =  GPIO_Pin_7;
    GPIO_Init(GPIOA, &GPIO_InitStruct);
#endif 

    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);

    /* Configure the chip select pin
     *        in this case we will use PE7 */
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_7;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_Init(GPIOE, &GPIO_InitStruct);

    GPIOE->BSRRL |= GPIO_Pin_7; // set PE7 high

    spi1_configuration();

    device_init();
    spi_test();
}

/*
 * This funtion is used to transmit and receive data
 * with SPI1
 *    data --> data to be transmitted
 * returns received value
 **/
char SPI1_ReadWrite1(unsigned char writedat)
{
    SPI1->DR = writedat; // write data to be transmitted to the SPI data register
    while( !(SPI1->SR & SPI_I2S_FLAG_TXE) ); // wait until transmit complete

    while( !(SPI1->SR & SPI_I2S_FLAG_RXNE) ); // wait until receive complete

    while( SPI1->SR & SPI_I2S_FLAG_BSY ); // wait until SPI is not busy anymore

    return SPI1->DR; // return received data from SPI data register
}

char SPI1_ReadWrite(unsigned char writedat)
{
    /* Loop while DR register in not emplty */
    while(SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_TXE) == RESET);

    /* Send byte through the SPI1 peripheral */
    SPI_I2S_SendData(SPI1, writedat);

    /* Wait to receive a byte */
    while(SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_RXNE) == RESET);

    /* Return the byte read from the SPI bus */
    return SPI_I2S_ReceiveData(SPI1);
}

/*
 *  * Access the PHY to determine link status
 *   */
int enc28j60CheckLinkState(void)
{
    unsigned short reg;
    int duplex;
    reg = enc28j60PhyRead(PHSTAT2);

    if (reg & PHSTAT2_LSTAT)
    {
        duplex = reg & PHSTAT2_DPXSTAT;
        printf("enc28j60 link on (duplex=%d)\r\n", duplex);
        return 1;
    }
    puts("enc28j60 link off\r\n");
    return 0;
}

void spi_test (void)
{
    uint8_t received_val = 0;
    int counter = 0;
    puts("spi testing...\r\n");
    while(counter++ < 10){
        GPIOE->BSRRH |= GPIO_Pin_7; // set PE7 (CS) low
        SPI1_ReadWrite(0xAA);  // transmit data
        received_val = SPI1_ReadWrite(0x00); // transmit dummy byte and receive data
        printf("testing 0x%x\r\n", received_val);
        GPIOE->BSRRL |= GPIO_Pin_7; // set PE7 (CS) high
    }
}
