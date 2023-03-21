#include <arpa/inet.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    char *addr1 = "10.53.46.178";
    char *addr2 = "10.53.46.256";

    unsigned long conv_addr = inet_addr(addr1);
    if (conv_addr == INADDR_NONE)
        printf("Error occured!  \n");
    else
        printf("Network ordered integer addr: %#lx \n", conv_addr);

    conv_addr = inet_addr(addr2);
    if (conv_addr == INADDR_NONE)
        printf("Error occured!  \n");
    else
        printf("Network ordered integer addr: %#lx \n\n", conv_addr);

    return 0;
}
