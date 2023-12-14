#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

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

void binary_to_ascii(const char *binary_str) {
    
    int len = strlen(binary_str);
    int i = 0;
    int decimal ;
    
    while (i < len) {
        
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
void pasteevrything(char *string)
{
    int index = 0 ;
    char *res ;
    while (string[index] != '\0')
    {
        res = binaryconv(string[index]);
        res = reverse(res);
        binary_to_ascii(res);
        free(res);
        index++ ;
    }
}   
int main()
{ 

    char *string = "1111000010011111100011111011001111101111101110001000111111100010100000001000110111110000100111111000110010001000" ;
          binary_to_ascii(string);
}
