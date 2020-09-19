//Make a program that read 5 integer numbers and print out them  

#include <stdio.h>

int main(void)
{
    int nums[5], i = 0;
    
    for(i = 0; i < 5; i++)
    {
        printf("Type a num: ");
        scanf("%i", &nums[i]);
    }
    
    for(i = 0; i < 5 ; i++)
    {
        printf("Num: %i \n",nums[i]);
    }
}