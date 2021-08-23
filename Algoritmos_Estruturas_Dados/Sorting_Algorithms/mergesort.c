
int count = 0;
int inversions(int array[], int len, int K);
void mergesort(int array[], int left, int right, int K);
void merge(int array[], int left, int mid, int right, int K);
 

/*   
    // Call the function to see how many pairs we can make and save into result variable
    result = inversions(array, N, K);
*/
 
int inversions(int array[], int len, int K) 
{
    // Call the function mergosort passsing the array to be sorted, the first index of it(which is always 0)
    // The length reduced by one, and pass the K-th multiple
    mergesort(array, 0, len - 1, K);
 
  return count;
}
 
void mergesort(int array[], int left, int right, int K) 
{
    // Check if there is a length to the array to be sorted, aka if the last element(the right one) is greater than
    // the first element (the left one)
    if (left < right) 
    {
        // If so, then we can merge then
 
        //define an variable to be the middle of the array length
        int mid = (left + right) / 2;
 
        // Recursive call to merge the left side, starting with the left(first element) and finishing on the 
        // middle of the original array
        mergesort(array, left, mid, K);
 
        // Do it again, but know starting with the first element after the middle one, aka the right 
        // side of the original array
        mergesort(array, mid + 1, right, K);
 
        // Then call the merg function again, but instead, passing now the full array, starting at left, middle and right
        merge(array, left, mid, right, K);
    }
}
 
void merge(int array[], int left, int mid, int right, int K) 
{
    // Define a couple of variables and the temporary array called "b"
    int i = left;
    int j = mid + 1;
    int k = 0;

    // Temporary array will have length of the half of the original array
    int b[right - left + 1];


    // Iterate though the original array, but divided in half
    // The first half is from i = 0 (left) until middle of the array
    // The second half is form the j(middle + 1) until the last element
    while (i <= mid && j <= right) 
    {
        //Check if the condition of the question is NOT right (<=) we want (>)
        if(array[i] <= K * array[j])
        {
            // If so, then it's not an par, than add 1 to i in order to keep iterating
            i++; 
        }
        else // aka if the condition is right (array[i] > K * array[j])
        {
            // Add to j in order to continue the search in the second half of the array
            j++;
            // Add all of the possible pairs into the variable count 
            count = count + (mid - i + 1);
        }
    }    


    // Re-start the variables in order to iterate though the arrays
    i = left;
    j = mid + 1;
    k = 0;


    // Check the array temporary and save into the original, but now putting them in order
    while (i <= mid && j <= right) 
    {
        if (array[i] <= array[j]) 
        {
            b[k++] = array[i++];
        } 
        else 
        {
            b[k++] = array[j++];
        }
    }


    // If there is any missing element that has not been add to the temporary array for whatever reason
    // add it iterating though both "sides" of the original array
    while (i <= mid)
    {
        b[k++] = array[i++];  
    }
 
    while (j <= right)
    {
        b[k++] = array[j++];  
    }

    // Copy back from the temporary array to the original array all the elements
    for (i = left, k = 0; i <= right; i++, k++) 
    {
        array[i] = b[k];
    }
}