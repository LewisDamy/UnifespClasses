//Make a program that convert meters to centimeters

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    float m = get_float("Meters: ");
    
    printf("Centimeters: %.1f \n", m*100);
}