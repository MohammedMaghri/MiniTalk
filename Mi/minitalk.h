#ifndef MINITALK_H 
#define MINITALK_H


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>


int lencount(char *string);
char *reverse(char *string);
char *inaryconv(unsigned char AR, int pid);
void checkthis(char string, pid_t pid);
void minishare(char string , int pid);
int atoifunction(char *string);
void handle_signal(int signal) ;
void putnbr(int number);
void paste (char string);
void binary_to_ascii( char *binary_str);
void functieight(int signal);

#endif 



