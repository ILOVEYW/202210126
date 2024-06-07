#include "serial.h"
#include "led.h"
#include "parse_cmd.h"

#define BUFFER_SIZE 1024

int main()
{
    int fd,fd_led,ret;
    char buff[BUFFER_SIZE];
    if((fd = open_port(1)) < 0)
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
        if(read(fd, buff, BUFFER_SIZE) > 0)
        {
            printf("the cmd is: %s", buff);
            parse_command(buff);
        }
    }while(strncmp(buff, "quit", 4));
    close(fd);
    return 0;
}