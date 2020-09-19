// Make a program that asks 4 grades and printout the grades and the mean

#include <stdio.h> 

int main(void)
{
    double grades[4];
    int i;
    
    for(i = 0; i < 4; i++)
    {
        printf("Type de grade %i: ",i + 1);
        scanf("%lf", &grades[i]);
    }
    
    printf("The grades are: \n");
    
    for(i = 0; i < 4; i++)
    {
        printf("Grade %i: %.2lf \n",i + 1, grades[i]);
    }
    
    double sum = 0;
    
    for(i = 0; i < 4; i++)
    {
        sum += grades[i];
    }
    
    printf("The mean is: %lf \n",sum/4);
}