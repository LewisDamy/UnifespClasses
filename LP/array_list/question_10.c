// Faça um Programa que leia dois vetores com 10 elementos cada. Gere um terceiro vetor de 20 elementos, cujos valores deverão ser compostos pelos elementos intercalados dos dois outros vetores.

#include <stdio.h> 

int main(void)
{
    int array1[10], array2[10], array3[20];
    
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
    
   for(int i = 0; i < 20; i++)
    {
       if(i < 10)
       {
           array3[i] = array1[i];
       }
       else
       {
           array3[i] = array2[i - 10];
       }
    }
    
    printf("Array3: ");
    
    for(int i = 0; i < 20; i++)
    {
        printf(" %i", array3[i]);
    }
    
    printf("\n");
}
