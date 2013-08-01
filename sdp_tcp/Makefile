
CC=arm-none-eabi-gcc
LD=arm-none-eabi-ld
AR=arm-none-eabi-ar

OBJCOPY=arm-none-eabi-objcopy

CFILES += enc_main.c
#CFILES += Retarget.c
#CFILES += STM32_Init.c
#CFILES += USART_Pol.c
CFILES += ip_arp_udp_tcp.c
CFILES += simple_server.c
CFILES += enc28j60.c

SRCROOT=../
INCLUDES = -ICMSIS/Device/ST/STM32F4xx/Include/ -ISTM32F4x7_ETH_Driver/inc
INCLUDES += -ICMSIS/Include
INCLUDES += -ISTM32F4xx_StdPeriph_Driver/inc
INCLUDES += -I$(SRCROOT)arch/armv7m/chip/stm32f40x/include/ -I.

CFLAGS  = -g3 -Wall --std=gnu99 $(INCLUDES)
CFLAGS += -mlittle-endian -mthumb -mcpu=cortex-m4 -mthumb-interwork -Xassembler -mimplicit-it=thumb
CFLAGS += -mfloat-abi=hard -mfpu=fpv4-sp-d16 -nostdlib -ffreestanding
CFLAGS += -Wdouble-promotion -fsingle-precision-constant -fshort-double
CFLAGS += -O2

CFLAGS += -D BUILD_TIME='"$(shell date)"' -D BUILD_REV=$(shell git shortlog | grep -E '^[ ]+\w+' | wc -l | sed -e "s/^[ ]*//g")
#CFLAGS += -save-temps --verbose -Xlinker --verbose

MOBJS=$(CFILES:.c=.o)

OBJ_DIR=obj
OBJS=$(patsubst %.o,$(OBJ_DIR)/%.o,$(MOBJS))

LIBETHA = libeth.a 

all: prebuild $(LIBETHA)

prebuild:
	mkdir -p obj

$(OBJ_DIR)/%.o: %.c
	$(CC) -c $< $(CFLAGS) -o $@

$(LIBETHA) : $(OBJS)
	$(AR) cru $@ $(OBJS) 

clean:
	rm -f $(LIBETHA)
	rm -rf obj

