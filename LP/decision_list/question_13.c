// Make a program that reads an number and shows the correspondent day of the week. (1 - Sunday, 2 - Monday, etc), if the user type another value, you should print out "Invalid Value"

#include <stdio.h>

int main(void)
{
    int day;
    
    printf("Type an number: ");
    scanf("%i", &day);
    
    if(day == 1)
    {
        printf("%i - Sunday\n",day);
    }
    else if(day == 2)
    {
        printf("%i - Monday\n",day);
    }
    else if(day == 3)
    {
        printf("%i - Tuesday\n",day);
    }
    else if(day == 4)
    {
        printf("%i - Wednesday\n",day);
    }
    else if(day == 5)
    {
        printf("%i - Thursday\n",day);
    }
    else if(day == 6)
    {
        printf("%i - Friday\n",day);
    }
    else if(day == 7)
    {
        printf("%i - Satuday\n",day);
    }
    else
    {
        printf("%i is not a valid day\n",day);
    }
}