// Program that reads three numbers and shows the largest and smallest numbers.

#include <stdio.h>

int main(void)
{
    float num1, num2, num3;
        
    printf("Type an number: ");
    scanf("%f", &num1);
    
    printf("Type another number: ");
    scanf("%f", &num2);
    
    printf("Type an  third number: ");
    scanf("%f", &num3);
    
    if(num1 > num2 && num1 > num3)
    {
        printf("%.1f is the biggest \n", num1);
    }
    else if(num2 > num1 && num2 > num3)
    {
        printf("%.1f is the biggest \n", num2);
    }
    else if(num3 > num2 && num3 > num1)
    {
        printf("%.1f is the biggest \n", num3);
    }
    if(num1 < num2 && num1 < num3)
    {
        printf("%.1f is the smallest \n", num1);
    }
    else if(num2 < num1 && num2 < num3)
    {
        printf("%.1f is the smallest \n", num2);
    }
    else if(num3 < num2 && num3 < num1)
    {
        printf("%.1f is the smallest \n", num3);
    }
}