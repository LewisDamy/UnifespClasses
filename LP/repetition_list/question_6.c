// Make a program that prints the numbers from 1 to 20, one below the other. Then modify the program so that it shows the numbers next to each other.

#include <stdio.h>

int main(void)
{
    int i = 0;
    
    while(i < 20)
    {
        i++;
        printf("%i ",i);
        //part 2: printf("%i \n",i);
    }
    printf("\n");
}