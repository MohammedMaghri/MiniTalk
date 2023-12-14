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
    while (index < 8)
    {
        if ( signal = SIGUSR1)
            allocation[index] = '1';
        else if (signal == SIGUSR2)
            allocation[index] = '0';
        index++ ;
    }
    allocation[index] = '\0' ;
    binary_to_ascii(allocation);
}
