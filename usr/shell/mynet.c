#include <stdio.h>
#include <string.h>

#include "shell.h"
#include "hello.h"
#include "enc28j60.h"
#include "simple_server.h"

static const unsigned char enc28j60_MAC[6] = {0x11, 0x02, 0x03, 0x04, 0x05, 0x33};

void start_net(void)
{
    //int ret = 1;
    // simple_server();
    // enc28j60Init((unsigned char *)enc28j60_MAC);
    // ret = enc28j60getrev();
    spi_test();
    // printf ("exit server return code(%d)\r\n", ret);
}

void hello_net(int argc, char **argv) {
    start_net();    
}

