// Make a program that asks the user un numebr and the print out "The number informed is:

#include <stdio.h>

int main(void)
{
    float num;
    
    printf("Type an number: ");
    scanf(" %f", &num);
    
    printf("The number informed is: %.1f \n", num);
}