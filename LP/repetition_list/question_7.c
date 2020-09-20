// Make a program that reads 5 numbers and reports the largest number.

#include <stdio.h>

int main(void)
{
    float num1, num2, num3, num4, num5;
    
    printf("Numbers: ");
    scanf("%f %f %f %f %f", &num1, &num2, &num3, &num4, &num5);
    
    if(num1 > num2 && num1 > num3 && num1 > num4 && num1 > num5)
    {
        printf("%f is the biggest\n", num1);
    }
    else if(num2 > num1 && num2 > num3 && num2 > num4 && num2 > num5)
    {
        printf("%f is the biggest\n", num2);
    }
    else if(num3 > num1 && num3 > num2 && num3 > num4 && num3 > num5)
    {
        printf("%f is the biggest\n", num3);
    }
    else if(num4 > num1 && num4 > num2 && num4 > num3 && num4 > num5)
    {
        printf("%f is the biggest\n", num4);
    }
    else if(num5 > num1 && num5 > num2 && num5 > num3 && num5 > num4)
    {
        printf("%f is the biggest\n", num5);
    }
    else 
    {
        printf("All the numbers are equal\n");
    }
}