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
char *reverse(char *string)
{
    int index = lencount(string) - 1;
    int incre = 0;
    char *allocation ;
    allocation = malloc(sizeof(char) * lencount(string)) + 1;
    while (index >= 0)
    {
        allocation[incre] = string[index];
        index-- ;
        incre++ ; 
    }   
    allocation[incre] = '\0';
    free(string);
    return allocation ;
}
char *inaryconv(unsigned char AR, int pid)
{
	int	i;
	int	j;
    char a;
    char res = 0;
	i = 7 ;
	j = 7 ;
    char *string;
    string = malloc(sizeof(string) * 8);
	int	arr[i];
    while (i >= 0)
    {
        
		arr[i] = (AR >> i) & 1;
        i--;
    }
    string[8] = '\0';
    while (j >= 0)
    {
        string[j] = arr[j] + '0';
        j--;
    }
    string = reverse(string);
    return (string);
}
void checkthis(char string, pid_t pid)
{
     if (string == '1')
            {
                kill(pid, SIGUSR1);
                usleep(20);
            }
            else if (string == '0')
            {
                kill(pid, SIGUSR2);
                usleep(20);
            }
}
void minishare(char string , int pid)
{
    char *res ;
    int index = 0 ;
    res = inaryconv(string,pid);
    while(res[index])
    {
        checkthis(res[index], pid);
        index++ ;
    }
}
