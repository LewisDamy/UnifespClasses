#include <stdio.h>

int main(void)
{
    int array1[10], array2[10], array3[10], totarray[30];
    
    for(int i = 0; i < 10; i++)
    {
        printf("Type the %ith from the first array: ",i + 1);
        scanf(" %i", &array1[i]);
    }
    
    for(int i = 0; i < 10; i++)
    {
        printf("Type the %ith from the second array: ",i + 1);
        scanf(" %i", &array2[i]);
    }
    
    for(int i = 0; i < 10; i++)
    {
        printf("Type the %ith from the third array: ",i + 1);
        scanf(" %i", &array3[i]);
    }
    
   for(int i = 0; i < 30; i++)
    {
       if(i < 10)
       {
           totarray[i] = array1[i];
       }
       else if (i < 20 && i > 10)
       {
           totarray[i] = array2[i - 10];
       }
       else 
       {
           totarray[i] = array3[i - 20];
       }
       
    }
     printf("Bigger Array: ");
    
    for(int i = 0; i < 30; i++)
    {
        printf(" %i", totarray[i]);
    }
    printf("\n");
}
