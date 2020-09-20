// Make a Program that asks in which shift you study. Ask to type M-morning or V-Afternoon or N-Night. Print the message "Good morning!", "Good afternoon!" or good night!" or "Invalid Value!", as appropriate.

#include <stdio.h>

int main(void)
{
    char shift;
    
    printf("Type M-morning or A-Afternoon or N-Night: ");
    scanf("%c", &turno);
    
    if(turno == 'M')
    {
        printf("Good Morning! \n");
    }
    else if(turno == 'A')
    {
        printf("Good Afternoon! \n");
    }
    else if(turno == 'N')
    {
        printf("Good NIght! \n");
    }
    else 
    {
        printf("Invalid Value!\n");
    }
}