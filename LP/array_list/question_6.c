//Make a program that ask 4 grades from 10 students, and calculate and store in an array the mean from each student,
// and them print out the number of students with mean greader or equals to 7.0

#include <stdio.h>

int main(void)
{
    int std[4][10];

    for(int i = 0; i < 4; i++) // loop from students
    {
        for(int j = 0; j < 10; j++) // loop from grades
        {
            printf("Student %i grade %i: ",i + 1,j + 1); // asks the user the grade
            scanf(" %i", &std[i][j]); // save the respective grade from the respective student
        }
    }
    
    int mean[4] = {0, 0, 0, 0}; // defined an array from all the means of the students
    
    for(int i =  0; i < 4; i++) // loop from students
    {
        for(int j = 0; j < 10; j++) // loop from grades
        {
            mean[i] += std[i][j]; // add the grades to an column from the mean array
        }
    }
    
    for(int i = 0; i < 4; i++) // loop from the mean array
    {
        if(mean[i]/10 >= 7) // if the mean is greater than or equals to 7 
        {
            printf("Student %i Approved \n", i + 1); // print out the student X is approved
        }
    }
}
    
    
    
    
    
    
    
    
//    for(int i = 0; i < 4; i++)
//    {
//        printf("Student %i: ",i + 1);
//       
//        for(int j = 0; j < 10; j++)
//        {
//            printf("%i ",std[i][j]);
//        }
//        
//        printf("\n");
//    }
