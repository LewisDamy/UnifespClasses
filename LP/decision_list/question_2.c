// Make a program that asks an value and prints if the value is positive or negative

#include <stdio.h>

int main(void)
{
    double num;
    
    printf("Type the first number: ");
    scanf("%lf", &num);
    
    if(num > 0)
    {
        printf("The number is greater than 0 \n");
    }
    else
    {
        printf("The number is less than 0 \n");
    }
}