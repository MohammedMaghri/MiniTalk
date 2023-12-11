#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char *binaryconv(unsigned char AR)
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
   return string ;
} 
int lencount(char *string)
{
    int index ;

    index = 0;

    while (string[index])
    {
        index++;
    }
    return (index);
}
char *reverse(char *reverse)
{
    int index ;
    int total ;

    total = 0;
    index = 0 ;
    
    total = lencount(reverse);
    char *allocation ;
    allocation = malloc(sizeof(char) * lencount(reverse));
    total -= 1 ;
    while (reverse[total])
    {
        allocation[index] = reverse[total];
        total--;
        index++;
    }
    allocation[index] = '\0';
    free(reverse);
    return allocation ;
}
 void characterreder(char *string)
{
    int index ;
    int total ;
    int res ;
    int number ;
    index = 0; 
    total -= 1;
    res = 0 ;
    total = lencount(string);
    number = 0 ;
    while (string[index])
    {
        
    }
}

int main()
{
    characterreder("0000 0000");
}