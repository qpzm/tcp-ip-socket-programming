#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
void error_handling(char *message);

int main(int argc, char* argv[])
{
    struct sockaddr_in addr1, addr2;
    char *str_ptr;
    char str_arr[20];

    addr1.sin_addr.s_addr=htonl(0x1020304);
    addr2.sin_addr.s_addr=htonl(0x1010101);

    str_ptr = inet_ntoa(addr1.sin_addr);
    // inet_ntoa는 char 포인터를 반환하므로 또 호출했을 때 기존 값을 덮어쓸 수 있다.
    strcpy(str_arr, str_ptr);
    printf("Dotted-Decimal notation1: %s \n", str_ptr);

    str_ptr = inet_ntoa(addr2.sin_addr);
    // 덮어쓰는 것 확인
    printf("Dotted-Decimal notation1: %s \n", str_ptr);
    printf("Dotted-Decimal notation1: %s \n", str_arr);
    return 0;
}
