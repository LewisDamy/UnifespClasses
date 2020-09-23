#include <stdio.h>

int main(void) 
{
    printf("Welcome to the Tic-tac-toe game!\n");
    
    int i, j, player = 1, position, line, column, numplays = 0, gameOn = 1;
    
    char play  = 'X';
    
    char table[3][3] = 
    {   {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '} }; //Creating the table with spaces in between
    
    
    
    for(i = 0; i < 3; i++) //loop through the lines of the table
    {
        for(j = 0; j < 3; j++) // loop through the columns of the table
        {
            if(j == 0) // if the colomn of the table is the first
            {
                printf("|"); // print this bar (it will print only the first's 3 vetical bars on the left side of the table)
            }
            printf(" %c |", table[i][j]); // else print out the table position and the bar
        }
        printf("\n");
    }
    
    
    
    while(gameOn) // until it ran out of plays or == 0(true), saving this in the variable nextplay == 1(false) 
    {
        if(player == 1)
        {
            play = 'X'; // if the player is the number 1 set him to use the 'X'
        }
        else
        {
            play = 'O'; // if the player is the number 2 set him to use the 'O'
        }
    
        do
        {
            printf("Player %d, type an position empty to play (1-9); \n", player); // ask the player an position
            scanf("%d", &position); // save the position in the variable 'position'

            // In the computer the array of the game in the order of [line][column] :  
                // [0][0], [0][1], [0][2]
                // [1][0], [1][1], [1][2]
                // [2][0], [2][1], [2][2]
    
            // For the user we have the table:
                // [1], [2], [3]
                // [4], [5], [6]                
                // [7], [8], [9]    
    
            line = (position - 1) / 3; //if the user asks the location: 
            
                                       //[1], [2] or [3]: the (position - 1) integer division by 3 will always be [0] aka line [0], 
                                       
                                       //[4], [5] or [6]: the (position - 1) integer division by 3 will always be [1] aka line [1], 
                                       
                                       //[7], [8] or [9]: the (position - 1) integer division by 3 will always be [2] aka line [2], 
                                       
            column = (position - 1) % 3; //if the user asks the location: 
            
                                         //[1]
                                         //[4] : the (position - 1) mod or remainder when dividing 3 will always be [0] aka column [0];
                                         //[7]
                                         
                                         
                                         //[2]
                                         //[5] : the (position - 1) mod or remainder when dividing 3 will always be [1] aka column [1];
                                         //[8]
                                         
                                         //[3]
                                         //[6] : the (position - 1) mod or remainder when dividing 3 will always be [2] aka column [2];
                                         //[9]

        }
        while(position < 1 || position > 9 || table[line][column] == 'X' || table[line][column] == 'O'); //do until the user plays inside the table aka between 1 and 9 or there are
                                                                                                         // 'X' or 'O' in the location that he wants to play which are not available
    
        table[line][column] = play; // save the player position to the respectively location in the table
    
        numplays ++; // add 1 to the play counter because there are only 9 possible plays on the game
    
        // print out the table after each play 
        for(i = 0; i < 3; i++)
        {
            for(j = 0; j < 3; j++)
            {
                if(j == 0)
                {
                    printf("|");
                }
                printf(" %c |", table[i][j]);
            }
            printf("\n");
        }
    
        //TODO
            //check if anyone won
            //print out who won and stop the game
            
        if(play == table[0][0] && play == table[0][1] && play == table[0][2] ||  //if there is an X in all of the first line OR
            play == table[1][0] && play == table[1][1] && play == table[1][2] || // there is an X in all of the second line OR
            play == table[2][0] && play == table[2][1] && play == table[2][2] || // there is an X in all of the third line OR
            play == table[0][0] && play == table[1][1] && play == table[2][2] || // there is an X in all the left to right diagonal OR
            play == table[0][2] && play == table[1][1] && play == table[2][0] || //  there is an X in all the right to left diagonal OR
            play == table[0][0] && play == table[1][0] && play == table[2][0] || // there is an X in all of the first column OR
            play == table[0][1] && play == table[1][1] && play == table[2][1] || // there is an X in all of the second column OR
            play == table[0][1] && play == table[1][1] && play == table[2][1] ) // there is an X in all of the third column OR
            {
                gameOn = 0; //stop the game
                printf("Congrats! The player %i won the game!", player); //show the winner
            }
        else
        {
            printf("Nobody won the game! \n");
        }
        
        if(player == 1) //after the play check if the player is the number 1
        {
            player = 2; // if the player is really the number 1, then switch to the player 2
        }
        else
        {
            player = 1; // else leave as it is
        }
    
        if(numplays == 9) // if the game reach 9 plays
        {
            gameOn = 0;
        }
    }
}