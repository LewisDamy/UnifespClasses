#include <stdio.h>

int main(void) 
{
    int tab [3][3];
    int i, j, k = 1;

    for(i = 0; i < 3; i++) 
    {
        for(j = 0; j < 3; j++) 
        {
            tab[i][j] = k++;
        }
    }

  for(i = 0; i < 3; i++) 
  {
        for(j = 0; j < 3; j++) 
        {
            printf("%d ", tab[i][j]);
        }
    printf("\n");
  }
}