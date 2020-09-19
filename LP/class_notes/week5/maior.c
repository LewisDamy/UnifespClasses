#include <stdio.h>

int main(void) 
{
  int a, b, maior;
  
  printf("Entre com o primeiro número:\n");
  scanf("%d", &a);
  
  printf("Entre com o segundo número:\n");
  scanf("%d", &b);
  
  if (a > b) 
  {
    maior = a;
  } 
  else 
  {
    maior = b;
  }
  
  printf("O maior dos dois números é o %d.\n", maior);
}