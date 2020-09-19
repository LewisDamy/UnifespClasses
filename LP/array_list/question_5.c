//Make a program that read 20 integer numbers and storage them in an array. Make another two arrays with the even and odds numbers and print out the three arrays.

#include <stdio.h> 

int main(void)
{
    int n = 1, m = 1;
    int all[4], even[n], odd[m];
    
    for(int i = 0; i < 20; i++) // Loop for the user to type all the 20 integer numbers
    {
        printf("Type %i number: ",i + 1);
        scanf(" %i", &all[i]); //Add the number for the all array in the ith position
    }
    
    for(int i = 0; i < 20; i++)
    {
        if(all[i] % 2 == 0) // For all the even numbers
        {
            even[n] = all[i]; // Add the same number from all array to even array
            n ++; // Add 1 to n, in order to keep adding the even numbers
        }
        else // For all the odds numbers 
        {
            odd[m] = all[i]; // Add the same number from all array to odd array 
            m ++; // Add 1 to m, in order to keep adding the odds numbers
        }
    }

    printf("The First Array: ");
    
    for(int i = 0; i < 20; i++)
    {
        printf("%i ", all[i]);
    }
    
    printf("\n");

    printf("The even = ");
    
    for(int i = 1; i < n; i++)
    {
        printf("%i ", even[i]);
    }

    printf("\n");

    printf("The odd = ");
    
    for(int i = 1; i < m; i++)
    {
        printf("%i ", odd[i]);
    }
    
    printf("\n");
}