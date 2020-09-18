#include <stdio.h>

int main(void) 
{
  double nota;
  
  do {
    printf("Entre com a nota:\n");
    scanf("%lf", &nota);
    
    if (nota < 0.0 || nota > 10.0) 
    {
      printf("Nota inválida.\n");
    }
  } 
  while (nota < 0.0 || nota > 10.0);
  
  printf("Nota lida: %lf\n", nota);
}