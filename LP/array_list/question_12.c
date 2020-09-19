// Given the age and height from 30 students, make an program that determine how many students has more than 13 years and the height less than the mean  of the 30 students.

#include <stdio.h>

int main(void)
{
    int age[30], avgheight = 0, result = 0;
    float height[30];
    
    for(int i = 0; i < 30; i++)
    {
        printf("Type the age from the %ith student: ",i + 1);
        scanf(" %i", &age[i]);
    }
    
    for(int i = 0; i < 30; i++)
    {
        printf("Type the height from the %ith student: ",i + 1);
        scanf(" %f", &height[i]);
    }
    
    for(int i = 0; i < 30; i++)
    {
        avgheight = (avgheight + height[i])/30;
    }
    
    for(int i = 0; i < 30; i++)
    {
        if(age[i] > 13)
        {
            if(height[i] > avgheight)
            {
                result++;
            }
        }
    }

    printf("students that has age greater than 13 and has the height less than the mean: %i.\n", result);

}

