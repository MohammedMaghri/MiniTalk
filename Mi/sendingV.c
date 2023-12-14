#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "minitalk.h"

int atoifunction(char *string)
{
    int index = 0 ;
    int number = 0 ;
    int negat = 1 ;

    while (string[index] && string[index] >= 9 && string[index] <= 13)
        index++ ;
    if (string[index] == '-' ||  string[index] == '+')
    {
        if (string[index] == '-')
            negat *= -1 ;
        index++;
    } 
    while (string[index] >= '0' && string[index] <=  '9')
        {
            number = (number * 10) + (string[index] - '0');
            index++ ;
        } 
        return number  * negat ;
}
void paste (char string)
{
    write(1,&string,1);
}
int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <pid>\n", argv[0]);
        return 1;
    }

    pid_t pid = (pid_t)atoifunction(argv[1]);
    int i = 0 ;
    while (argv[2][i] != '\0')
    {
        minishare(argv[2][i], pid); 
        i++ ;
    }
    printf("%d" , i);
}