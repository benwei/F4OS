#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stm32f4xx_spi.h>
#include <stm32f4xx_gpio.h>
#include <stm32f4xx_rcc.h>
void RCC_Configuration(void)
{
    ErrorStatus HSEStartUpStatus;

    // RCC_DeInit();
    RCC_HSEConfig(RCC_HSE_ON);
    HSEStartUpStatus = RCC_WaitForHSEStartUp();
    if(HSEStartUpStatus == SUCCESS)
    {
        puts("RCC HSE ON\r\n");
        while(RCC_GetSYSCLKSource() != 0x08);
    } 
}

void init_spi1(void)
{
    SPI_InitTypeDef  SPI_InitStructure;
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_Configuration();

    /* Enable SPI1 and GPIOA clocks */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1, ENABLE);
    /* Configure SPI1 pins:  SCK, MISO and MOSI */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    puts("Enable SPI1 and GPIOA Clocks\r\n");

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 ;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    /* SPI1 configuration */ 
    SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
    SPI_InitStructure.SPI_Mode = SPI_Mode_Master;
    SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;
    SPI_InitStructure.SPI_CPOL = SPI_CPOL_Low;
    SPI_InitStructure.SPI_CPHA = SPI_CPHA_1Edge;
    SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;
    SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_4;
    SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;
    SPI_InitStructure.SPI_CRCPolynomial = 7;
    SPI_Init(SPI1, &SPI_InitStructure);

    /* Enable SPI1  */
    SPI_Cmd(SPI1, ENABLE); 
    puts("Configure and Enable SPI1\r\n");
}

unsigned char SPI1_ReadWrite(unsigned char writedat)
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

