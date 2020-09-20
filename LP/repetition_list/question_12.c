//Develop a multiplication table generator, capable of generating the multiplication table of any integer between 1 and 10. The user must inform which number he wants to see the multiplication table. The output should be according to the example below:
//      Times table of 5:
//          5 X 1 = 5
//          5 X 2 = 10
//          ...
//          5 X 10 = 50

#include <stdio.h>

int main(void)
{
    int num;
    
    printf("Type a number: ");
    scanf("%i", &num);
    
    printf("Time Table of %i: \n",num);
    
    for(int i = 0; i < 11; i++)
    {
        printf("%i X %i \n", num, i, num*i);
    }
}