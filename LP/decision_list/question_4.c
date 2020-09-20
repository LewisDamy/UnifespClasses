//Make a Program that checks if a typed letter is a vowel or consonant.

#include <stdio.h>
#include <math.h>
#include <string.h>

int main(void)
{
    char letter;
    
    printf("Type an letter ");
    scanf("%c", &letter);
    
    if(letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u')
    {
        printf("The letter '%c' is an vowel \n", letter);
    }
    else
    {
        printf("The letter '%c' is an consonant \n", letter);
    }
}