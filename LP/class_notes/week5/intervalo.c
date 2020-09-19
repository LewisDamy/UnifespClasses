#include <stdio.h>

int main(void) 
{
  int limiteInferior, limiteSuperior, i;
  
  printf("Entre com o limite inferior do intervalo:\n");
  scanf("%d", &limiteInferior);

  do 
  {
    printf("Entre com o limite superior do intervalo:\n");
    scanf("%d", &limiteSuperior);
  } 
  while(limiteSuperior <= limiteInferior + 1);

  printf("{ ");

  for(i = limiteInferior + 1; i < limiteSuperior-1; i++) 
  {
    printf("%i, ", i);
  }
  
  printf(" %d }\n", limiteSuperior-1);
}