#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char    *ft_copy(char *string ,char *thestring)
{
    int number ;

    number = 0 ;

    while (thestring[number])
    {
        string[number] = thestring[number];
        number++ ; 
    }
    string[number] = '\0';
    return (string);
}
void Binaryconv(unsigned char AR)
{
    int i = 7 ;
    int arr[8] ;
    while (i >= 0)
    {
        ar[(AR >> i) - ]
     
        i--;
    }
    printf("\n");
}
void Convhandle(char *string)
{
    int i ;
}
struct Minitalk
{
    char string[7];
    int number;
};

int main(int argc, char **argv)
{
    int n = 12 ;
    printf("%d\n" , n >> 1);
    Binaryconv('a');
  char  numbeB = 0b01100001 ;
    printf("%c" , numbeB);
    struct Minitalk person;
    ft_copy(person.string, "Thii");
    printf("%s\n" ,person.string);
    if (argc < 2)
    {
        printf("Usage: <%d> <Message>\n", getpid());
        return 0;
    }
    else
    {
        printf("{%d}}\n" , fork());
        sleep(1);
        printf("this the <%d> and this   Message: %s\n", getpid() , argv[1]);
        sleep(1);
        printf("and this is the <%d>" , getppid());
    }
}