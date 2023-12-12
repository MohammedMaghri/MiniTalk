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
 int characterreder(char *string)
{
    int index ;
    int addition ;
    int i ;

    i = 0 ;
    int division = 1; 
    int total  = 0 ;
    addition = 1 ;

    index = lencount(string - 1);
    
    while (i <= index)
    {
        if (string[i] == '1')
        {
            total += division ;
        }
        division *= 2 ;
        i++;
    }
    return total ;
}
void binary_to_ascii(const char *binary_str) {
    int len = strlen(binary_str);
    int i, j, decimal;
    i = 0 ;
    j = 0 ;  
    while (i < len) {
        decimal = 0;
        while  (j < 8) 
        {
            decimal = decimal * 2 + (binary_str[i + j] - '0');
            j++ ;
        }
        i += 8 ;
        
        printf("%d", decimal);
    }
    printf("\n");
}

int main() { 
    const char *binary_string = "01100001" ;
    binary_to_ascii(binary_string);

    return 0;
}
