//Make a program that asks the radius of an circle, and calculate the area

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    float pi = 3.141592;
    
    float r = get_float("Radius ");
    
    float a = pi*r*r;
    
    printf("The area of the circle: %.3f \n",a);
}