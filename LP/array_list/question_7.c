// Make a program that read an array from 5 integer numbers and show the sum, multiplication and the numbers

#include <stdio.h>

int main(void)
{
    int nums[4];
    
    for(int i = 0; i < 4; i++) // Loop for the user type an integer number
    {
        printf("Type the %i number: ",i + 1); // from human convention we start to count from 1
        scanf(" %i", &nums[i]); // Save the number from the user within the respective location in the sums array
    }
    
    int sum = 0;
    
    for(int i = 0; i < 4; i++) // loop for the nums array
    {
        sum += nums[i]; // add the values from array to the sum
    }
    
    float mult = 1.0; // This variable is set to 1 because 0*anything is 0
    
    for(int i = 0; i < 4; i++) // loop for the nums array 
    {
        if(nums[i] != '0') // if the num inside the array is not 0 
        {
            mult *= nums[i]; //multiplied into the variable mult
        }
        else // if the any number from the array is 0 
        {
            mult = 0; // set the mult variable to 0 because we already know the mult is 0
        }
    }
    
    printf("The sum is %i\nThe multiplication is %.2f\n", sum, mult);
    
    printf("The numbers are: ");
    
    for(int i = 0; i < 4; i++) // loop for the nums array 
    {
        printf(" %i",nums[i]); // print the number from each location of the array
    }
    
    printf("\n");
}