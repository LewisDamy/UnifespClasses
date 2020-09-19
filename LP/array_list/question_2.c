//Make a program that read 5 integer numbers and print out the inverse order of them

#include <stdio.h> 

int main(void)
{
    double nums[10];
    int i;
    
    for(i = 0; i < 10; i++)
    {
        printf("Type number %i: ",i + 1);
        scanf("%lf", &nums[i]);
    }
    
    for(i = 9; i > -1; i--)
    {
        printf("number %i: %lf \n",i + 1, nums[i]);
    }
}