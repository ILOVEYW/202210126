#ifndef __LED_H
#define __LED_H

#include <linux/types.h>
#include <linux/kernel.h>
#include <linux/errno.h>
#include <stdio.h>      
#include <stdlib.h>     
#include <unistd.h>       
#include <sys/types.h>   
#include <sys/stat.h>     
#include <fcntl.h>      
#include <termios.h>      
#include <errno.h>      
#include <string.h>  
#include <sys/select.h> 
#include <sys/time.h> 

void LED_OFF();
void LED_ON();
void LED_BLINK(int time, int count);

#endif