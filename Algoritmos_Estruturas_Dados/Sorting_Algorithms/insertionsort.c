
void insertionsort(int array[], int N, int level)
{   

    // Check if the size of the array is less or equals to 1
    if (N <= 1)
    {
        // If so, then nothing change
        return;
    }
    
    // Call the function again (RECURSIVILY) 
        // But now "reducing the size of the array, because the 1-th element is suppost to be already sorted"
        // Add one to our variable level
    insertionsort(array, N - 1, level + 1);

    // By using an recursive function, from this line on it will only start working after we made
    // all the possible calls of the funcion, aka until N - 1 >= 1 and then return

    // Set the variable value to the N-1'th position of the array, aka the previeous before the last
    int value = array[N - 1];

    // Set j to be the one previous the one that is before the last, aka the 3-th last item in the array
    int j = N - 2;

    // Keep iterating until you find an element that is greater thant the value that we want to insert
    // or if j is less than or equals to j
    while (j >= 0 && array[j] > value)
    {
        // Define that j+1'th element of the array to be the one that we are seeking to see who is the biggest
        // because we know that the j-th element is bigger than the last element which is j+1-th
        array[j+ 1] = array[j];
        // Decrease by one j
        j--;
    }


    // NOTE: this j is decreased by one after finished the loop!
    // Then it will be in the position before our new last element, which we found that it was the biggest
    array[j + 1] = value;

    // Print the following output
    //printf("%i %i %i\n", level, value, j + 1);
}

/*

// Call the funcion insertion sort
insertionsort(array, N, 1);

*/