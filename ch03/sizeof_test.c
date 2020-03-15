#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    char message[6]; // {0, 0, 0, 0, 0, 0}
    int str_len, fd;

    fd = open("data.txt", O_RDONLY);
    str_len = read(fd, message, sizeof(message)-1);
    printf("%s\n", message);
    return 0;
}
