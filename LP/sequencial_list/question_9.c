// Mkae a program that asks the user the temperature in Fahrenheit and convert to Celcuius
//      Tip: The formula is C = 5 * ((F-32) / 9).

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    float f = get_float("Faherenheit: ");
    
    float c = 5 * ((f - 32) / 9);
    
    printf("Celsius: %.1f \n",c);
}