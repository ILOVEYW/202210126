#include "parse_cmd.h"
#include "led.h"

void parse_command(char* command) 
{
    int status = 0;
    command[strcspn(command, "\n")] = '\0';

    if(strlen(command) == 4 && (strncmp(command, "b", 1)) == 0)
    {
        status = 1;
    }
    else if((strncmp(command, "clo", 3)) == 0)
         {
             status = 1;
         }
         else if((strncmp(command, "ope", 3)) == 0)
              {
                  status = 1;
              }
              else {
                    status = 0;
                    printf("error cmd");
              }
    
    if(status == 1 && (strncmp(command, "clo", 3)) == 0)
    {
        printf("led off\n");
        LED_OFF();
    }
    else if(status == 1 && (strncmp(command, "ope", 3)) == 0)
            {
                printf("led on\n");
                LED_ON();
            }
    else if(status == 1 && (strncmp(command, "b", 1)) == 0)
            {
                char buff[3];
                int i = 1;
                for(;i < 4; i ++)
                {
                    buff[i-1] = command [i];
                }
                buff[i-1] = '\0';
                int value = atoi(buff);
                int flicker_period = value / 100;
                int count = value % 100;
                printf("time and the count is:%d %d\n", flicker_period, count);
                LED_BLINK(flicker_period, count);
            }
            else 
            {
                printf("cmd is error\n");
                status = 0;
            }

}
