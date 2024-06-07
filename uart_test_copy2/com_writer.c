#include "serial.h"
#define BUFFER_SIZE 1024

int main()
{
    int fd;
    char buff[BUFFER_SIZE];
    if((fd = open_port(0)) < 0)
    {
        perror("open port");
        return 1;
    }
    if(set_com_config(fd, 115200, 8, 'N', 1) < 0)
    {
        perror("set_com_config");
        return 1;
    }
    do
    {
        printf("Input:");
        if(fgets(buff, BUFFER_SIZE, stdin) == NULL)
        {
            perror("fgets");
            break;
        }
        write(fd, buff, strlen(buff));
    }while(strncmp(buff, "quit", 4));
    close(fd);
    return 0;
}