//

#include <stdio.h>

int main(void)
{
    int tab[3][3];
    int i, j, k = 1;

    //Set the table all places to 0
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j <3; j++)
        {
            tab[i][j] = 0;
        }
    }

    printf("The game has 3 columns and 3 lines, it's start from 0,\n"
            "[0,0] [0,1] [0,2]\n"
            "[1,0] [1,1] [1,2]\n"
            "[2,0] [2,1] [2,2]\n"
            "e.g. [0][1] is the line 0 column 1\n"
            "\nThe players have to input numbers 1 and 2 in the 'value' \n\n"
          );
          

    int column = 0;
    int line = 0;
    int value = 0;

    do
    {
        printf("Enter the column that you want to play: ");
        scanf(" %i", &column);
    }
    while(column > 3 || column < 0);

    do
    {
        printf("Enter the line that you want to play: ");
        scanf(" %i", &line);
    }
    while(line > 3 || column < 0);

    do
    {
        printf("Enter an value for tab[%i][%i]: ", column, line);
        scanf(" %i", &value);
    }
    while(value != 1 && value != 2);


    tab[column][line] = value;

    //Print the table from game
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            printf("%i ",tab[i][j]);
        }
        printf("\n");
    }
}