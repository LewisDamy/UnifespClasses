// Make a program that reads 5 numbers and gives the sum and average of the numbers.

#include <stdio.h>

int main(void)
{
    float num1, num2, num3, num4, num5;
    
    printf("Numbers: ");
    scanf("%f %f %f %f %f", &num1, &num2, &num3, &num4, &num5);
    
    printf("The sum is: %.1f and the medium is %.1f \n", num1+num2+num3+num4+num5, (num1+num2+num3+num4+num5)/5);
    
}