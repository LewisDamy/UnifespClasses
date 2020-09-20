// Assuming that the population of country A is of the order of 80,000 inhabitants with an annual growth rate of 3% and that the population of B is 200,000 inhabitants with a growth rate of 1.5%. Make a program that calculates and writes the number of years needed for the population of country A to exceed or equal the population of country B, while maintaining growth rates.

#include <stdio.h>

int main(void)
{
    int popA = 80000;
    float crescA = 1.03;
    int popB = 200000;
    float crescB = 1.015;
    
    int ano = 1;
    
    while(popA <= popB)
    {
        popA *= crescA;
        popB *= crescB;
        ano += 1;
    }
    
    printf("Tempo estimado: %i \n", ano);
}