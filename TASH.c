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
char  binaryreader(unsigned char string, int number[])
{
    int index ;

    index = 7 ;
    while (index >= 0)
    {
        string = (string << 1) | number[index];
        index--; 
    }
    return string ;
}
char binaryArrayToChar(int binaryArray) {
    char result = 0;
    return result;
}
void	Binaryconv(unsigned char AR)
{
	int	i;
	int	j;
    char a;
    char res = 0;
	i = 7 ;
	j = 7 ;
	int	arr[i];
    while (i >= 0)
    {
		arr[i] = (AR >> i) & 1;
        i--;
    }
    for (int x = 0; x <= 7; x++) {
        res |= arr[x] << (7 - x);
    }
    printf("%c" ,res);
}

struct Minitalk
{
    char string[7];
    int number;
};

int main(int argc, char **argv)
{
    Binaryconv('z');
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