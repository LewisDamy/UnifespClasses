// Make a program that read 10 characters in a array and print out how many consonants are found and which they are.

#include <stdio.h>

int main(void)
{
    char cons[10];
    int i;
    
    for(i = 0; i < 10; i++)
    {
        printf("Type %i character: ",i + 1);
        scanf(" %c", &cons[i]);
    }
    
    int tot = 0;
    
    for(i = 0; i < 10; i++)
    {
        if(!(cons[i] == 'a' || cons [i] == 'e' || cons[i] == 'i' || cons[i] == 'o' || cons[i] == 'u'))
        {
            tot += 1;
        }
    }
    printf("The total consonants are %i \n", tot);
    
    for(i = 0; i < 10; i++)
    {
        if(!(cons[i] == 'a' || cons [i] == 'e' || cons[i] == 'i' || cons[i] == 'o' || cons[i] == 'u'))
        {
            printf("Consonant: %c \n", cons[i]);
        }
    }
    printf("\n");
}

