#include <stdio.h>

int main() 
{
  double populacaoA = 80000.0, populacaoB = 200000.0;
  double taxaA = 0.03, taxaB = 0.015;
  int anos = 0;

  while(populacaoA < populacaoB) 
  {
    populacaoA = populacaoA + (populacaoA * taxaA);
    populacaoB = populacaoB + (populacaoB * taxaB);
    anos++;
  }

  printf("População do país A: %lf.\n", populacaoA);
  printf("População do país B: %lf.\n", populacaoB);
  printf("Passaram-se %d anos até que a população de A passasse ou igualasse a população de B.\n", anos);
}