// Make a program that read a array A with 10 integer numbers and calculate the sum of the squares from the elements of the array.

#include <stdio.h>
#include <math.h>

int main(void)
{
    int vect[10];
    
    for(int i = 0; i < 10; i++)
    {
        printf("Type the %i of the array: ",i + 1);
        scanf(" %i", &vect[i]);
    }
    
    int sumsqt = 0, result = 0;
    
    for(int i = 0; i < 10; i++)
    {
        int x = 2;
        sumsqt = pow(vect[i], 2);
        result += sumsqt;
    }
    
    printf("The sum of the squares of the array is: %i\n",result);
}