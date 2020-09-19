// Make a program that asks the user his age and height from 5 persons, and keep the user info in the users array. Print out the age, height in the inverse order asked.

#include <stdio.h>

int main(void)
{
    double heige[5][2][2];
    
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 2; j ++)
        {
            printf("Type the age from the person %i: ",i + 1);
            scanf(" %lf", &heige[i][j]);
            
            for(int k = 0; k < 2; k++)
            {
                printf("Type the height from the person %i: ",i + 1);
                scanf(" %lf", &heige[i][j][k]);
            }
        }
    }
    
    for(int i = 0; i < 5; i ++)
    {
            for(int j = 0; j < 2; j++)
            {
                for(int k = 0; k < 2; k ++)
                {
                    printf("The person %i has age:%lf and heigh: %lf \n",i ,heige[i][j], heige[i][j][k]);
                }
            }
    }
}