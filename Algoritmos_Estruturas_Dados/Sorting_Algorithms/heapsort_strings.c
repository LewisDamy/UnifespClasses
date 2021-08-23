#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void build_HeapSort(char** array, int i, int M);

// Swap function to change the elements from the array
void swap(char **a, char **b) 
{
    // Note: pass the element by reference in order to change it correctly
    // Define an temporary variable
    char *temp;
    // copy save the address of that variable into the temp var
    temp = *b;
    // save the adress from variable a into variable b
    *b = *a;
    // save new adress from variable temp which was the former b-value/address into a
    *a = temp;
}

void HeapSort(char** array, int M)
{
    int i;

    for (i = M/2; i >= 0; i--)
    {
        //printf("%i ",i);
        build_HeapSort(array, i, M);

    }
    //printf("\n");
        printf("build_heap: ");

    for (i = 0; i < M; i++)
    {
        printf("%s ", array[i]);
    }
    printf("\n");


    char temp[20];
    
    for (i = M - 1; i >= 1; i--)
    {
        strcpy(temp, array[i]);
        strcpy(array[i], array[0]);
        strcpy(array[0], temp);
        build_HeapSort(array, 0, i);
    }
}

int string_compare(char* string1, char* string2)
{
    int i, size;

    if (strcmp(string1, string2) >= 0)
        size = strlen(string1);

    else
    {
        size = strlen(string2);
    }

    for (i = 0; i < size; i++)
    {
        if(string1[i] > string2[i])
        {
            // First string is greater
            return 1;
        }
        else if (string1[i] < string2[i])
        {
            // Second string is greater
            return 0;
        }
    }
    return 0;
}

void build_HeapSort(char** array, int i, int M)
{
    int left, right, max;

    left = 2*i + 1;
    right = 2*i + 2;

    if (left < M && string_compare(array[left], array[i]))
    {           
        max = left;
    }
    else
    {
        max = i;
    }
    if (right < M && (string_compare(array[right], array[max])>0) && (string_compare(array[right], array[left])>0))
    {
        max = right;
    }
    char temp[20];

    if (max != i)
    {
        strcpy(temp, array[i]);
        strcpy(array[i], array[max]);
        strcpy(array[max], temp);
        //swap(&array[i], &array[max]);

        build_HeapSort(array, max, M);
    }
}


int error_checker(char** array,int N)
{
    // Create an string of size max allowed to save the wrong word
    char wrong_word[20];
    int i, j;


    // Iterate though the words of the list with size N
    for (i = 0; i < N; i++)
    {
        // Iterate though each letter of the word
        for (j = 0; j < strlen(array[i]); j++)
        {
            // Check if the word is not from 'a' -> 'z'
            if(array[i][j] > 122 || array[i][j] < 97)
            { 
                // If so, then copy that word and save it in the wrong_word array
                strcpy(wrong_word, array[i]);
                // Print out the wrong word
                printf("a palavra %s eh invalida\n",wrong_word);
                // Return 0 aka we found an error on the words
                return 0;
            }
        }
    }
    // If we haven't found an error in words
    return 1;
}



int main(void)
{
    int N, i, M, j;

    // Scan N
    scanf("%i", &N);

    // Create an string of pointers
    char** array;

    // Set each index i of the string to allocate the N-numbers of element that will be added
    array = (char**) malloc(N*sizeof(char*));
    
    // Iterate to get words from user inputs
    for (i = 0; i < N; i++)
    {
        // In each i-th index allocate 20 spaces(which is the size max of the letters)
        array[i] = (char*) malloc(20*sizeof(char));
        // Scan the word and save it as each letter goes to one of the spaces on the i-th position of the array
        scanf("%s", array[i]);
    }
    
    // Scan M
    scanf("%i", &M);

    // Create array of M integers to save the array that we will use
    int arr_heap[M];

    for (i = 0; i < M; i++)
    {
        // Scan the info and save in the i-th location
        scanf("%i", &arr_heap[i]);
    }

    // Create another string of pointers
    char** array_def;

    // Alocate enought space for all the words that we are going to use
    array_def = (char**) malloc(M*sizeof(char*));

    for (i = 0; i < M; i++)
    {
        // In each i-th index allocate 20 spaces(which is the size max of the letters)
        array_def[i] = (char*) malloc(20*sizeof(char));

        // copy to the array definitive the i-th position of the original array, which is
        // the element from the array of ints arr_heap
        strcpy(array_def[i], array[arr_heap[i]]);
    }
    
    // Call the function to see if there is some letter that's not valid
    if (error_checker(array, N) == 0)
    {
        // If the function error_checker returned 0 then, they found an error
        // kill the main function
        return 0;
    }




    HeapSort(array_def, M);


    printf("palavras: ");

    for (i = 0; i < M; i++)
    {
        printf("%s ", array_def[i]);
    }
    printf("\n");

    // Iterate though each element in element of array
    for (i = 0; i < N; i++)
    {   
        // Free the i-th pointer
        free(array[i]);
    }
    // Free the array of pointers
    free(array);

    // Iterate though each element of array_def
    for (i = 0; i < M; i++)
    {
        // Free the i-th pointer
        free(array_def[i]);
    }
    // Free the array of pointers
    free(array_def);
}