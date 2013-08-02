
SDP_CFILES += ip_arp_udp_tcp.c
SDP_CFILES += simple_server.c
SDP_CFILES += enc28j60.c
//SDP_CFILES += string.c
SDP_CFILES += spi.c
SDP_CFILES += stm32f4xx_gpio.c
SDP_CFILES += stm32f4xx_rcc.c
SDP_CFILES += stm32f4xx_i2c.c
SDP_CFILES += stm32f4xx_spi.c

SDP_INCS += -I$(SRCROOT)/net/STM32F4xx_StdPeriph_Driver/inc/
SDP_INCS += -I$(SRCROOT)/net/CMSIS/Device/ST/STM32F4xx/Include/
SDP_INCS += -I$(SRCROOT)/net/CMSIS/Include/
