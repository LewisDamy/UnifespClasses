// Make a program for reading a student's two partial grades. The program should calculate the average achieved per student and present:
//      The message "Approved", if the average reached is greater than or equal to seven;
//      The message "Failed", if the average is less than seven;
//      The message "Approved with Distinction", if the average is equal to ten.
#include <stdio.h>

int main (void)
{
    double grade1, grade2;
    
    printf("Type the first grade: \n");
    scanf("%lf", &grade1);
    
    printf("Type the second grade: \n");
    scanf("%lf", &grade2);
    
    float mean;
    
    mean = (grade1+grade2)/2;
    
    if(mean == 10.0)
    {
        printf("Approved with Distinction \n");
    }
    else if(mean >= 7.0)
    {
        printf("Approved \n");
    }
    else if(mean < 7.0)
    {
        printf("Failed \n");
    }
    
}