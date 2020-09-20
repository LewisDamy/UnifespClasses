// Make a program that asks the price of three products and tells you which product you should buy, knowing that the decision is always for the cheapest.

#include <stdio.h>
#include <math.h> 
#include <string.h>

int main(void)
{
    float num1, num2, num3;
        
    printf("Type the first product price: ");
    scanf("%f", &num1);
    
    printf("Type the second product price: ");
    scanf("%f", &num2);
    
    printf("Type the third product price: ");
    scanf("%f", &num3);
    
    if(num1 < num2 && num1 < num3)
    {
        printf("%.1f is the cheapest \n", num1);
    }
    else if(num2 < num1 && num2 < num3)
    {
        printf("%.1f is the cheapest \n", num2);
    }
    else 
    {
        printf("%.1f is the cheapest \n", num3);
    }
}