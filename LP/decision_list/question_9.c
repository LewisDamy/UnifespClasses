// Make a Program that reads three numbers and shows them in descending order.

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
    
    if(num1 > num2 &&  num1 > num3 && num2 > num3)
    {
        printf("%.f > %.1f > %.1f \n", num1, num2, num3);
    }
    else if(num2 > num1 &&  num2 > num3 && num1 > num3)
    {
        printf("%.f > %.1f > %.1f \n", num2, num1, num3);
    }
    else if(num2 > num1 &&  num2 > num3 && num3 > num1)
    {
        printf("%.f > %.1f > %.1f \n", num2, num3, num1);
    }
    else if(num3 > num1 &&  num3 > num2 && num1 > num2)
    {
        printf("%.f > %.1f > %.1f \n", num3, num1, num2);
    }
    else if(num3 > num2 &&  num3 > num2 && num2 > num1)
    {
        printf("%.f > %.1f > %.1f \n", num3, num2, num1);
    }
    else
    {
        printf("All of the three numbers are the same \n");
    }
}