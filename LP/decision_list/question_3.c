// Make a Program that checks if a letter typed is "F" or "M". As the letter writes: F - Female, M - Male, Invalid Gender.

#include <stdio.h>
#include <math.h>
#include <string.h>

int main(void)
{
    char letter;
    
    printf("Type an letter ");
    scanf("%c", &letter);
    
    if(letter == 'F')
    {
        printf("%c - Female \n", letter);
    }
    else if(letter == 'M')
    {
        printf("%c - Male \n", letter);
    }
    else
    {
        printf("Invalid Value \n");
    }
}