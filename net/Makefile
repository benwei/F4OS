
CC=arm-none-eabi-gcc
LD=arm-none-eabi-ld
AR=arm-none-eabi-ar
OBJCOPY=arm-none-eabi-objcopy


INCLUDES = -ICMSIS/Device/ST/STM32F4xx/Include/ -ISTM32F4x7_ETH_Driver/inc
INCLUDES += -ICMSIS/Include
INCLUDES += -ISTM32F4xx_StdPeriph_Driver/inc

CFLAGS  = -g3 -Wall --std=gnu99 $(INCLUDES)
CFLAGS += -mlittle-endian -mthumb -mcpu=cortex-m4 -mthumb-interwork -Xassembler -mimplicit-it=thumb
CFLAGS += -mfloat-abi=hard -mfpu=fpv4-sp-d16 -nostdlib -ffreestanding
CFLAGS += -Wdouble-promotion -fsingle-precision-constant -fshort-double
CFLAGS += -O2

CFLAGS += -D BUILD_TIME='"$(shell date)"' -D BUILD_REV=$(shell git shortlog | grep -E '^[ ]+\w+' | wc -l)
#CFLAGS += -save-temps --verbose -Xlinker --verbose

ETH_DIVERS_SRC=STM32F4x7_ETH_Driver/src
SRC_DIRS+=$(ETH_DIVERS_SRC)
CFILES = $(wildcard $(ETH_DIVERS_SRC)/*.c)
MOBJS=$(CFILES:.c=.o)
OBJ_DIR=obj
OBJS=$(patsubst %.o,$(OBJ_DIR)/%.o,$(MOBJS))

LIBETHA = libeth.a 

all: prebuild $(LIBETHA)

prebuild:
	@for i in $(SRC_DIRS) ; do \
	mkdir -p "obj/$$i" ; \
	done
	echo $(OBJS)

$(OBJ_DIR)/%.o: %.c
	$(CC) -c $< $(CFLAGS) -o $@

$(LIBETHA) : $(OBJS)
	$(AR) cr $@ $(OBJS) 

clean:
	rm -f $(LIBETHA)
	rm -rf obj

