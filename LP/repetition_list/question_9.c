//Make a program that prints on the screen only the odd numbers between 1 and 50

#include <stdio.h>

int main(void)
{
    int num = 0;
    
    for(int i = 0; i < 50; i++)
    {
        num++;
        if(num % 2 != 0)
        {
            printf("%i ",num);
        }
    }
    printf("\n");
}