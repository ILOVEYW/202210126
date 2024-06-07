#include "led.h"

void LED_OFF()
{
    int fd,ret;
    fd = open("/dev/leds", O_RDWR|O_NOCTTY|O_NDELAY);
    if(fd > 0)
    {
        ret = ioctl(fd, 0, 0);
    }
    close(fd);
}

void LED_ON()
{
    int fd,ret;
    fd = open("/dev/leds", O_RDWR|O_NOCTTY|O_NDELAY);
    if(fd > 0)
    {
        ret = ioctl(fd, 1, 0);
    }
    close(fd);
}

void LED_BLINK(int time,int count)
{
    int i;
    for(i = 0; i < count; i ++)
    {
        sleep(time);
        LED_ON();
        sleep(time);
        LED_OFF();
    }
}