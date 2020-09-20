// Make a program that calculates the factorial of an integer provided by the user. Ex .: 5! = 5.4.3.2.1 = 120

#include <stdio.h>

int main(void)
{
    int num;
    
    printf("Type a number: ");
    scanf("%i", &num);
    
    int fact = num * 1;
    
    for(int i = 1; num > i; i++)
    {
        fact = fact * i;
    }
    printf("The factioral of %i is %i \n", num, fact);
}