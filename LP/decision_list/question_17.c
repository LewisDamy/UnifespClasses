// Make a Program that asks for a number corresponding to a certain year and then inform if this year is leap or not.

#include <stdio.h>

int main(void)
{
    int leapyear;
    
    printf("Type an year: ");
    scanf("%i", &leapyear);
    
    if(leapyear % 4 == 0)
    {
        printf("The year %i is a leap year\n", leapyear);
    }
    else
    {
        printf("The year %i is not a leap year\n", leapyear);
    }
}