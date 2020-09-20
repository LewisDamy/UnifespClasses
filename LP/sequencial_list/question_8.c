// Make a program that asks the user how much do you make per hour and the time of work hours from month
// And then print out the total of your sallary per month 

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    float w = get_float("Type how much do you make per hour: ");
    float h = get_float("Type the number of hours worked per month: ");
    
    float s = h*w;
    
    printf("The total amount of money do you make per month is: %.1f \n",s);
    
}