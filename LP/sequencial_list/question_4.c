//Make a program that asks 4 grades and show the mean

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    float sum = 0, mean = 0;
    
    int i = 0;
    
    while(i < 4)
    {
        int grade = get_float("Type the grade: ");
        i++;
        sum += grade;
        mean = sum/i;
    }
    
    printf("The mean  of the grades: %.1f \n", mean);
}