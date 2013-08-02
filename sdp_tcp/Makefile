
CC=arm-none-eabi-gcc
LD=arm-none-eabi-ld
AR=arm-none-eabi-ar

OBJCOPY=arm-none-eabi-objcopy

include build.mk
CFILES += $(SDP_CFILES)

SRCROOT=../
INCLUDES += -I. -isystem $(SRCROOT)/include
INCLUDES += -I../net/STM32F4xx_StdPeriph_Driver/inc/
INCLUDES += -I../net/CMSIS/Device/ST/STM32F4xx/Include/
INCLUDES += -I../net/CMSIS/Include/

CFLAGS  = -g3 -Wall --std=gnu99 $(INCLUDES)
CFLAGS += -mlittle-endian -mthumb -mcpu=cortex-m4 -mthumb-interwork -Xassembler -mimplicit-it=thumb
CFLAGS += -mfloat-abi=hard -mfpu=fpv4-sp-d16 -nostdlib -ffreestanding
CFLAGS += -Wdouble-promotion -fsingle-precision-constant -fshort-double
CFLAGS += -O2

CFLAGS += -D BUILD_TIME='"$(shell date)"' -D BUILD_REV=$(shell git shortlog | grep -E '^[ ]+\w+' | wc -l | sed -e "s/^[ ]*//g")

MOBJS=$(CFILES:.c=.o)

OBJ_DIR=obj
OBJS=$(patsubst %.o,$(OBJ_DIR)/%.o,$(MOBJS))

LIBETHA = libeth.a 

all: image
	
image: prebuild
	make $(LIBETHA)
	make -C ..

prebuild:
	mkdir -p obj

$(OBJ_DIR)/%.o: %.c
	$(CC) -c $< $(CFLAGS) -o $@

$(LIBETHA) : $(OBJS)
	$(AR) cru $@ $(OBJS) 

clean:
	rm -f $(LIBETHA)
	rm -rf obj

