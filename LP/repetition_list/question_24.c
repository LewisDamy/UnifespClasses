// Make a program that calculates and shows the arithmetic mean of N notes.

#include <stdio.h>

int main(void)
{
    printf("Type an number: ");
    scanf("%i", &n);
    
    double notas[n];
    
    for(int i = 0; i < n; i++)
    {
        printf("Grade %i: ", i + 1);
        scanf("%lf", &notas[i]);
    }
    
    double sum = 0.0;
    
    for(int j = 0; j < n; j++)
    {
        sum += notas[j];
    }
    printf("The mean of the %d grades is %.3f\n",n, sum /n);
}