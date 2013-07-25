
CC=arm-none-eabi-gcc
LD=arm-none-eabi-ld
AR=arm-none-eabi-ar

OBJCOPY=arm-none-eabi-objcopy


LWIP_CFILES +=lwip_v1.3.2/port/STM32F4x7/F4OS/sys_arch.c
LWIP_CFILES +=lwip_v1.3.2/port/STM32F4x7/F4OS/ethernetif.c
LWIP_CFILES +=lwip_v1.3.2/port/STM32F4x7/Standalone/ethernetif.c
LWIP_CFILES +=lwip_v1.3.2/src
LWIP_CFILES +=lwip_v1.3.2/src/api/netdb.c
LWIP_CFILES +=lwip_v1.3.2/src/api/sockets.c
LWIP_CFILES +=lwip_v1.3.2/src/api/tcpip.c
LWIP_CFILES +=lwip_v1.3.2/src/api/netbuf.c
LWIP_CFILES +=lwip_v1.3.2/src/api/api_msg.c
LWIP_CFILES +=lwip_v1.3.2/src/api/netifapi.c
LWIP_CFILES +=lwip_v1.3.2/src/api/api_lib.c
LWIP_CFILES +=lwip_v1.3.2/src/api/err.c

LWIP_SNMP_CFILES +=lwip_v1.3.2/src/core/snmp/msg_out.c
LWIP_SNMP_CFILES +=lwip_v1.3.2/src/core/snmp/asn1_enc.c
LWIP_SNMP_CFILES +=lwip_v1.3.2/src/core/snmp/mib_structs.c
LWIP_SNMP_CFILES +=lwip_v1.3.2/src/core/snmp/asn1_dec.c
LWIP_SNMP_CFILES +=lwip_v1.3.2/src/core/snmp/mib2.c
LWIP_SNMP_CFILES +=lwip_v1.3.2/src/core/snmp/msg_in.c

LWIP_IP6_CFILES +=lwip_v1.3.2/src/core/ipv6/ip6_addr.c
LWIP_IP6_CFILES +=lwip_v1.3.2/src/core/ipv6/inet6.c
LWIP_IP6_CFILES +=lwip_v1.3.2/src/core/ipv6/icmp6.c
LWIP_IP6_CFILES +=lwip_v1.3.2/src/core/ipv6/ip6.c

LWIP_CFILES +=lwip_v1.3.2/src/core/ipv4/ip_addr.c
LWIP_CFILES +=lwip_v1.3.2/src/core/ipv4/inet.c
LWIP_CFILES +=lwip_v1.3.2/src/core/ipv4/autoip.c
LWIP_CFILES +=lwip_v1.3.2/src/core/ipv4/ip.c
LWIP_CFILES +=lwip_v1.3.2/src/core/ipv4/inet_chksum.c
LWIP_CFILES +=lwip_v1.3.2/src/core/ipv4/icmp.c
LWIP_CFILES +=lwip_v1.3.2/src/core/ipv4/ip_frag.c
LWIP_CFILES +=lwip_v1.3.2/src/core/ipv4/igmp.c

LWIP_CFILES +=lwip_v1.3.2/src/core/udp.c
LWIP_CFILES +=lwip_v1.3.2/src/core/sys.c
LWIP_CFILES +=lwip_v1.3.2/src/core/dhcp.c
LWIP_CFILES +=lwip_v1.3.2/src/core/memp.c
LWIP_CFILES +=lwip_v1.3.2/src/core/stats.c
LWIP_CFILES +=lwip_v1.3.2/src/core/netif.c
LWIP_CFILES +=lwip_v1.3.2/src/core/dns.c
LWIP_CFILES +=lwip_v1.3.2/src/core/tcp.c
LWIP_CFILES +=lwip_v1.3.2/src/core/pbuf.c
LWIP_CFILES +=lwip_v1.3.2/src/core/mem.c
LWIP_CFILES +=lwip_v1.3.2/src/core/tcp_out.c
LWIP_CFILES +=lwip_v1.3.2/src/core/init.c
LWIP_CFILES +=lwip_v1.3.2/src/core/tcp_in.c
LWIP_CFILES +=lwip_v1.3.2/src/core/raw.c

LWIP_CFILES +=lwip_v1.3.2/src/netif/loopif.c
LWIP_CFILES +=lwip_v1.3.2/src/netif/etharp.c
LWIP_CFILES +=lwip_v1.3.2/src/netif/slipif.c

# PPP
LWIP_PPP_CFILES +=lwip_v1.3.2/src/netif/ppp/auth.c
LWIP_PPP_CFILES +=lwip_v1.3.2/src/netif/ppp/vj.c
LWIP_PPP_CFILES +=lwip_v1.3.2/src/netif/ppp/randm.c
LWIP_PPP_CFILES +=lwip_v1.3.2/src/netif/ppp/pap.c
LWIP_PPP_CFILES +=lwip_v1.3.2/src/netif/ppp/chpms.c
LWIP_PPP_CFILES +=lwip_v1.3.2/src/netif/ppp/md5.c
LWIP_PPP_CFILES +=lwip_v1.3.2/src/netif/ppp/ipcp.c
LWIP_PPP_CFILES +=lwip_v1.3.2/src/netif/ppp/ppp.c
LWIP_PPP_CFILES +=lwip_v1.3.2/src/netif/ppp/ppp_oe.c
LWIP_PPP_CFILES +=lwip_v1.3.2/src/netif/ppp/magic.c
LWIP_PPP_CFILES +=lwip_v1.3.2/src/netif/ppp/chap.c
LWIP_PPP_CFILES +=lwip_v1.3.2/src/netif/ppp/fsm.c
LWIP_PPP_CFILES +=lwip_v1.3.2/src/netif/ppp/lcp.c

INCLUDES = -ICMSIS/Device/ST/STM32F4xx/Include/ -ISTM32F4x7_ETH_Driver/inc
INCLUDES += -ICMSIS/Include
INCLUDES += -ISTM32F4xx_StdPeriph_Driver/inc

CFLAGS  = -g3 -Wall --std=gnu99 $(INCLUDES)
CFLAGS += -mlittle-endian -mthumb -mcpu=cortex-m4 -mthumb-interwork -Xassembler -mimplicit-it=thumb
CFLAGS += -mfloat-abi=hard -mfpu=fpv4-sp-d16 -nostdlib -ffreestanding
CFLAGS += -Wdouble-promotion -fsingle-precision-constant -fshort-double
CFLAGS += -O2

CFLAGS += -D BUILD_TIME='"$(shell date)"' -D BUILD_REV=$(shell git shortlog | grep -E '^[ ]+\w+' | wc -l | sed -e "s/^[ ]*//g")
#CFLAGS += -save-temps --verbose -Xlinker --verbose

ETH_DIVERS_SRC=STM32F4x7_ETH_Driver/src
SRC_DIRS+=$(ETH_DIVERS_SRC)
CFILES = $(wildcard $(ETH_DIVERS_SRC)/*.c)
MOBJS=$(CFILES:.c=.o)

# LWIP
INCLUDES+=-Iinclude
INCLUDES+=-Ilwip_v1.3.2/src/include/ipv4
INCLUDES+=-Ilwip_v1.3.2/src/include
INCLUDES+=-Ilwip_v1.3.2/port/STM32F4x7
LWIP_OBJS=$(LWIP_CFILES:.c=.o)

OBJ_DIR=obj
OBJS=$(patsubst %.o,$(OBJ_DIR)/%.o,$(MOBJS))
OBJS+=$(patsubst %.o,$(OBJ_DIR)/%.o,$(LWIP_OBJS))

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
	$(AR) cru $@ $(OBJS) 

clean:
	rm -f $(LIBETHA)
	rm -rf obj

