#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>

void error_handling(char *message);

int main(int argc, char *argv[]) {
    char *addr = "10.53.46.178";
    struct sockaddr_in addr_inet;

    if (!inet_aton(addr, &addr_inet.sin_addr))
        error_handling("Conversion error!");
    else
        printf("Network ordered integer addr: %#x \n",
               addr_inet.sin_addr.s_addr);

    return 0;
}

void error_handling(char *message) {
    fputs(message, stderr);
    fputs("\n", stderr);
    exit(1);
}
