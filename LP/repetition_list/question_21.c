//Make a program that asks for an integer and determines whether or not it is a prime number. A prime number is one that is divisible only by itself and by 1.

#include <stdio.h>

int main(void)
{
    printf("Type an number: ");
    scanf("%i", &num);
    
    if(num == 1 || num == 2 || num 3 || num == 5 || num == 7)
    {
        printf("%i is a prime number \n", num);
    }
    else if(num % 2 == 0 || num % 3 == 0 || num % 5 == 0 || num % 7 == 0) // using Sieve of Erastothenes method
    {
        printf("%i is not a prime number \n", num);
    }
    else
    {
        printf("%i is a prime number \n", num);
    }
    
}