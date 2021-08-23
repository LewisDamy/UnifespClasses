// Swap function to change the elements from the array
void swap(int *a, int *b) 
{
    // Note: pass the element by reference in order to change it correctly

    // Define an temporary variable
    int temp;

    // copy save the address of that variable into the temp var
    temp = *b;
    // save the adress from variable a into variable b
    *b = *a;
    // save new adress from variable temp which was the former b-value/address into a
    *a = temp;
}


int QuickSort(int array[], int left, int right)
{
    // Define the last element as being the pivot variable
    int lastElemPivot = array[right];
    // Set i to be the first element of the array, which is always 0
    int i = left;
    int j;

    // Keep iterating, starting from the 0 index of array until the last element (right - 1)
    for (j = left; j <= right - 1; j++)
    {
        // Check if the j-th element of the array is smaller or equals to the last element of the array
        if(array[j] <= lastElemPivot)
        {
            /*If so, then swap the i-th element of the array with the j-th element which is less than the 
              last element of the array
              e.g.: 1 3 5 7 4 2, lasElemtPivot = 2, array[i] = 1 (DON'T ENTER IN IF STATEMENT)
              e.g.: 1 3 5 7 4 2, lasElemPivot = 2, array[i] = 3, Swap(2, 3) ==> 1 2 5 7 4 3
             */
            swap(&array[i], &array[j]);
            i++;
        }
    }

    // After finished that, swap the last element with the first
    swap(&array[i], &array[right]);
    return i;
}


// Function to find the K-th Smallest element
int kthSmallest(int array[], int left, int right, int k)
{
    // Check until K became greater than 0 and until the size of the array is 1
    if (k > 0 && k <= right - left + 1)
    {   
        // Set our PivotIndex to be the value that will result after calling the QuickSort function 
        int PivotIndex = QuickSort(array, left, right);

        // If the value of Pivot is the same as the K-th element, then we found the sequence ordinated
        // until the k-th element, return that array found
        if (PivotIndex - left == k - 1)
            return array[PivotIndex];
        
        // If not, then check if the Pivot found in the QuickSort function is greater than the K-th element
        // that we are searching
        if (PivotIndex - left > k -  1)
            // If so, then recursive call the functin again but know passing the value pivot - 1
            return kthSmallest(array, left, PivotIndex - 1, k);

        // If the Pivot found is less thna K-th element
        else
            // Then, recursively calling the function with PivotIndex increase by one
            return kthSmallest(array, PivotIndex + 1, right, k - PivotIndex + left - 1);

    }

    // Error, out of max memory space of alocating integers
    return __INT_MAX__;
}

/*    
// Call the function by passing 0 as the first element and N-1,
// N - 1 being the size of the array, and K
    kthSmallest(array, 0, N-1, K)
*/