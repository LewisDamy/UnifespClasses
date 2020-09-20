//Make a program that asks 2 numbers and print out the biggerst

#include <stdio.h>

int main(void)
{
    double num1, num2;
    
    printf("Type the first number: ");
    scanf("%lf", &num1);
    
    printf("Type the secont number: ");
    scanf("%lf", &num2);
    
    if(num1 > num2)
    {
        printf("The first number is the biggest \n");
    }
    else if(num1 < num2)
    {
        printf("The second number is the biggest \n");
    }
    else
    {
        printf("The numbers are equal \n");
    }
}