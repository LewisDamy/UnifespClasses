//Make a program that roll a dice and show how many times each face went

#include <stdio.h>
#include <time.h>

int main(void)
{
    int dice[6] = {0, 0, 0, 0, 0, 0}, rollTimes, i, face;
    
    srand(time(0));
    
    printf("Type the number of rolls: ");
    scanf("%d", &rollTimes);
    
    for(i = 0; i < rollTimes);
    {
        face = rand() % 6;
        dice[face]++;
    }
    
    for(i = 0; i < 6; i++)
    {
        printf("The face %d appears %d times. \n",i + 1, dice[i]);
    }
}