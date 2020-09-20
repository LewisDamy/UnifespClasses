// Make a program that asks for a note, between zero and ten. Show a message if the value is invalid and keep asking until the user enters a valid value.

#include <stdio.h>

int main(void)
{
    float num;
    
    do
    {
        printf("Type an numebr between 0 and 10: ");
        scanf("%f", &num);
    }
    while (num < 0 || num > 10);
    // or while (!(0 <= num && num <= 10));
}