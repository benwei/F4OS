#include <stdio.h>
#include <string.h>

#include "shell.h"
#include "hello.h"
#include "enc28j60.h"
#include "simple_server.h"

const unsigned char enc28j60_MAC[6] = {0x11, 0x02, 0x03, 0x04, 0x05, 0x33};

void hello_net(int argc, char **argv) {
    int rev = 0;
    printf ("enc28j60 init...\r\n");
    enc28j60Init((unsigned char *)enc28j60_MAC);  
    simple_server();
    enc28j60Init((unsigned char *)enc28j60_MAC);

    rev = enc28j60getrev();
    printf ("rev=%d\r\n", rev);
}
