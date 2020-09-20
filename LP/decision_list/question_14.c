// Make a program that reads the two partial marks obtained by a student in a subject over the course of a semester, and calculates their average. The assignment of concepts follows the table below:
//    Average Utilization Concept
//    Between 9.0 and 10.0 A
//    Between 7.5 and 9.0 B
//    Between 6.0 and 7.5 C
//    Between 4.0 and 6.0 D
//    Between 4.0 and zero E
// The algorithm must show on the screen the notes, the average, the corresponding concept and the message “APPROVED” if the concept is A, B or C or “FAILED” if the concept is D or E.

#include <stdio.h>

int main(void)
{
    float num1, num2, mean;
    
    printf("Type the two grades: ");
    scanf("%f %f", &num1, &num2);
    
    mean = (num1+num2)/2.0;
    
    if(mean >= 9.0)
    {
        printf(
            "Grades: %.2f, %.2f \n"
            "Mean: %.2f \n"
            "Average Utinization Concept: A\n"
            "Approved\n"
            ,num1, num2, mean);
    }
    else if(mean > 7.5 || mean < 6.0)
    {
        printf(
            "Grades: %.2f, %.2f \n"
            "Mean: %.2f \n"
            "Average Utinization Concept: B\n"
            "Approved\n"
            ,num1, num2, mean);
    }
    else if(mean > 6.0 || mean < 7.5)
    {
        printf(
            "Grades: %.2f, %.2f \n"
            "Mean: %.2f \n"
            "Average Utinization Concept: C\n"
            "Approved\n"
            ,num1, num2, mean);
    }
    else if(mean > 4.0 || mean < 6.0)
    {
        printf(
            "Grades: %.2f, %.2f \n"
            "Mean: %.2f \n"
            "Average Utinization Concept: D\n"
            "Failed\n"
            ,num1, num2, mean);
    }
    else 
    {
        printf(
            "Grades: %.2f, %.2f \n"
            "Mean: %.2f \n"
            "Average Utinization Concept: E\n"
            "Failed\n"
            ,num1, num2, mean);
    }
}