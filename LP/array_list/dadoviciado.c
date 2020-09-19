#include <stdio.h>
#include <stdlib.h>
#include <time.h> // to use time funcion

int main(void)
{
    int n, num;
    float dice;
    float numVect[6] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0};  //save the frequency of each number from 1 to 6 in an array

    srand(time(NULL)); // generate random numbers from the exacly time, so it will not be repeated

    printf("Type the number of times that you want to roll the dice: "); // ask the user how many times to roll
    scanf(" %i", &n); //save the variable

    for(int i = 0; i < n; i++) // loop over the quantity of rolls of the dice
    {
        dice = rand() % 6 + 1; // generate a random number or "roll the dice"

        printf("%.0f ", dice); // print the number

        if(dice == 1.0) // if dice rolled in 1

            numVect[0] ++; // save the value in array
        }
        else if(dice == 2.0) // if dice rolled in 2
        {
            numVect[1] ++; // save the value in array
        }
        else if(dice == 3.0) // if dice rolled in 3
        {
            numVect[2] ++; // save the value in array
        }
        else if(dice == 4.0) // if dice rolled in 4
        {
            numVect[3] ++; // save the value in array
        }
        else if(dice ==5.0) // if dice rolled in 5
        {
            numVect[4] ++; // save the value in array
        }
        else if(dice ==6.0) // if dice rolled in 6
        {
            numVect[5] ++; // save the value in array
        }
    }

    printf("\n");

    for(int i = 0; i < 6; i++) // loop from the array
    {
        printf("Average of %i: %.2f \n",i + 1, numVect[i]/n); //print the average of each number 1 to 6
    }
}