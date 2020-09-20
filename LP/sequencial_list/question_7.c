// Make a program that asks the aera of an square and print out the double of this area

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    float l = get_float("Side of the square: ");
    
    float a = l*l;
    
    printf("The double of the area of the square is: %.1f \n",a*2);
    
}