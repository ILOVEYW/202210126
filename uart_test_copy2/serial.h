#ifndef __SERIAL_H
#define __SERIAL_H

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

int set_com_config(int fd,int baud_rate,int data_bits,char parity,int stop_bits);
int open_port(int i);



#endif