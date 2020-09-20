// Make a program that receives two whole numbers and generates the whole numbers that are in the range they understand

#include <stdio.h>

int main(void)
{
    int num1, num2, diff = 0;
    
    printf("Type 2 numbers: ");
    scanf("%i %i", &num1, &num2);
    
    if(num1 > num2)
    {
        diff = num1 - num2;
        for(int i = 1; i < diff; i++)
        {
            printf("%i ", num1 - i);
        }
    }
    else if(num2 > num1)
    {
            diff = num2 - num1;
        for(int i = 1; i < diff; i++)
        {
            printf("%i ", num2 - i);
        }
    }
}