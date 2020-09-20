//Make a program that asks n people your age, at the end the program should check if the average age of the class varies between 0 and 25.26 and 60 and greater than 60; and then, say if the class is young, adult or elderly, according to the calculated average.

#include <stdio.h>

int main(void)
{
    printf("Type an the quantity of persons: ");
    scanf("%i", &n);
    
    int p[n];
    
    for(int i = 0; i < n; i++)
    {
        printf("Type the age from person %i: ",i + 1);
        scanf("%i", &p[i]);
    }
    
    double sum = 0.0;
    
    for(int j = 0; n > j; j++)
    {
        sum += p[j];
    }
    
    printf("The mean of the %i ages of the class is %.2lf \n", n, sum/n);
}
    