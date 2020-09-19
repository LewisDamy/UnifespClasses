#include <stdio.h>

int main() 
{
  int numero;
  
  printf("Entre com um número:\n");
  scanf("%d", &numero);
  
  if(numero == 0)
  {
    printf("Número zero.\n");
  } 
  else if(numero > 0) 
  {
    printf("Número positivo.\n");
  } 
  else 
  {
    printf("Número negativo.\n");
  }
}