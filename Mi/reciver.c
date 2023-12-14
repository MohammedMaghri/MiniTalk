#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "minitalk.h"

int lencount(char *string)
{   
    int index = 0 ;
    while (string[index])
    {
        index++ ;
    }
    return index ;
}
void paste (char string)
{
    write(1,&string,1);
}
void binary_to_ascii( char *binary_str) {
    
    int len = lencount(binary_str);
    int i = 0;
    int decimal ;
    
    while (binary_str[i] && i < len) {
        
        decimal = 0;
        int j = 0;
        while (j < 8) {
            decimal = decimal * 2 + (binary_str[i + j] - '0');
            j++;
        }

        printf("%c", decimal);
        i += 8;
    }
}
void functieight(int signal)
{
    int index = 0 ;
    char *allocation ;
    allocation = malloc(sizeof(char) * 8);
    if(index < 8)
    {
        if ( signal == SIGUSR1)
        {
            paste('1');
            allocation[index] = '1';
        }
        else if (signal == SIGUSR2){
            paste('0');
            allocation[index] = '0';
        }
        index++ ;
    }
    allocation[index] = '\0' ;
    binary_to_ascii(allocation);
}

int main() {
    printf("Receiver process PID: %d\n", getpid());

    signal(SIGUSR1, functieight);
    signal(SIGUSR2, functieight);
    while (1) {
        pause();
    }

    return 0;
}