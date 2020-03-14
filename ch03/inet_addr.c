#include <stdio.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
    char *addr1="1.2.3.4";
    char *addr2="1.2.3.256";

    unsigned long conv_addr=inet_addr(addr1);
    char *pointer = (char *) &conv_addr; // A pointer to the first octet of the word.
    if(conv_addr==INADDR_NONE)
        printf("Error occured! \n");
    else
        //Prints 0x4030201 because interprets little endian 4 bytes of unsigned long type
        //into human readable big endian.
        printf("Network ordered integer addr : %#lx \n", conv_addr);

        printf("Print preserving byte order: ");
        for (int i = 0; i < 4; i++)
        {
            printf("%02x ", (unsigned int) pointer[i]);
        }
        putc('\n', stdout);

    conv_addr=inet_addr(addr2);
    if(conv_addr==INADDR_NONE)
        printf("Error occured \n");
    else
        printf("Network ordered integer addr: %#lx \n\n", conv_addr);
    return 0;
}
