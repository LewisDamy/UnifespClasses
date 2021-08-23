
/*
Pseudocode:

set a swap counter to a non-zero value
repeat until the swap counter is 0:
    reset swap counter to 0
    look at adjacent pair
        if two adjancent elements are
        not in order, swap them and
        add one to the swap counter
*/

void bubble_sort(int Array[], int size_array)
{
    int i, temp,swap_counter, winner;

    swap_counter = -1;
    
    while(swap_counter != 0)
    {
        swap_counter = 0;

        for(i = 0; i < (size_array - 1); i++)
            {
                if (Array[i] > Array[i + 1])
                {
                    temp = Array[i + 1];
                    Array[i + 1] = Array[i];
                    Array[i] = temp;\
                    swap_counter ++;
                }
            }
    }

    for(i = 0; i < size_array; i++)
    {
        printf("%i ", Array[i]);
    }
    printf("\n");
}
