// Make a program that asks 2 numbers and print out the sum

#include <stdio.h>

int main(void)
{
    float num1, num2;
    
    printf("Type the first number: ");
    scanf(" %f", &num1);
    
    printf("Type the second number: ");
    scanf(" %f", &num2);
    
    printf("The sum of %.1f and %1.f is: %.1f \n",num1, num2, num1+num2);
}