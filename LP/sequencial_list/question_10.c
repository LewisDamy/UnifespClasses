// Modify the last program an shift from the imput of Celsius to Fahrenheit

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    float c = get_float("Celcius: ");
    
    float f = ((9*c) / 5) + 32;
    
    printf("Fahrenheit: %.1f \n",f);
}