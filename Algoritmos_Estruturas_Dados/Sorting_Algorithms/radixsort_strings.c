#include <stdio.h>
#include <string.h>


void CountingSort(char A[][21], int N, int i);

void RadixSort(char A[][21], int d, int N)
{
    int i;

    // Iterate though the words, from the left to the right
    for (i = d - 1; i >= 0; i--)
    {
        // Call the CountingSort function
        CountingSort(A, N, i);
    }
}




void CountingSort(char A[][21], int N, int i)
{
    // Create an array of the same size as the original to insert the result
    char B[N][21];
    int j;
    // Set k to be the size of the alfabet 
    int k = 27;
    // Create array of size 27 for allocating the number of letters counted
    int C[27];

    // Set all values of the C array to be 0
    for(j = 0; j < k; j++)
    {
        C[j] = 0;
    }
    
    // Iterate though the array
    for (j = 0; j < N; j++)
    {
        // Check if the i-th element (it will change according to the Radix Func)
        // is an space
        if(A[j][i] == ' ')
            // If so add 1 to the 0-position of the array C (where we count the space)
            C[0]++;
        else
            // Else if its an letter, subtract 96 (knowing a = 97) and save it on the 
            // position related of C aka from 1 till 27 each letter of the ASCII table
            // that starts on 97 till 122
            C[A[j][i] - 96]++;
    }

    // Cumulative sum
    for (j = 1; j < k; j++)
    {
        C[j] = C[j] + C[j - 1];
    }

    // Print the elements of the C array for each iteration of RadixSort function
    for (j = 0; j < k; j++)
    {
        printf("%d ",C[j]);
    }
    printf("\n");

    // Iterate though the array
    for (j = N - 1; j >= 0; j--)
    {
        // Check if j-th i-th element is an space
        if(A[j][i] == ' ')
        {
            // If so then copy that element of A[j] into the B array on the C[0] -1 position
            strcpy(B[C[0]- 1], A[j]);
            // Decrease the counting of spaces that we have by one
            C[0] = C[0] - 1;
        }
        // Aka if it's an letter
        else
        {
            // Copy the A[j] element to the B[] array
            strcpy(B[C[A[j][i] - 96] - 1], A[j]);
            // Decrease by one the number of letters that we have by one
            C[A[j][i] - 96] = C[A[j][i] - 96] - 1;
        }
    }

    for(i = 0; i < N; i++)
    {
        // Copy all elements from the array B to the array original A[]
        strcpy(A[i], B[i]);
    }
}

int main(void)
{
    int i, N, j, d = 0;

    // Scan N
    scanf("%i", &N);

    // Create array of fixed size of char
    char Array[N][21];

    // Iterate to get the words from the user
    for (i = 0; i < N; i++)
    {
        // Scan the entire word
        scanf("%s", Array[i]);
        // Iterate thought the letters from the word
        for(j = 0; j <= 21; j++)
        {
            // Check if it's an uppercase letter
            if(Array[i][j] >= 65 && Array[i][j] <= 90)
            {
                // if so, add 32 to become an lowercase letter
                Array[i][j] = Array[i][j] + 32;
            }
            // also check if the length of the word is greater than d
            if(strlen(Array[i]) > d)
            {
                // If so, then set it to be it the biggest letter
                d = strlen(Array[i]);
            }
        }
    }

    // Iterate though the word of the array
    for (i = 0; i < N; i++)
    {
        // Iterate though the letters of the word
        for (j = strlen(Array[i]); j < d; j++)
        {
            // if the letter is less than the size of the biggest letter
            // se the j-th location to be equal to an space 
            Array[i][j] = ' ';
        }
        // At the end of each word, add an "\0" in order to define the end of it
        Array[i][j] = '\0';
    }
    

    int list[2];

    for (i = 0; i < 2; i++)
    {
        // Scan the two elements of the list
        scanf("%i", &list[i]);
    }

    // Iterate though the words
    for (i = 0; i < N; i++)
    {
        // Iterate though the letters
        for (j = 0; j < 21; j++)
        {
            // Check if it's an lowercase letter
            if(Array[i][j] >= 97 && Array[i][j] <= 122)
            {
                // If so, then print the letter
                printf("%c", Array[i][j]);
            }
            else // If it's not an letter 
            {
                // Print the "dot" and end the line
                printf(".\n");
                // And break the interation from the letter
                // Aka we reach the end of it
                break;
            }
        }
    }

    // Print the max lenght of the word
    printf("%i\n",d);

    // Call the RadixSort function passing the array 
    // and the length of the biggest word and the N-words 
    RadixSort(Array, d,N);

    // Iterate as the user asks
    for(i = list[0] - 1; i < list[0] + list[1] - 1; i++)
    {
        // Print the word that the user wants
        printf("%s\n", Array[i]);
    }
}