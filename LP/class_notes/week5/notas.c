#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() 
{
  int tamanhoTurma;
  
  do 
  {
    printf("Digite o tamanho da turma (1-300):\n");
    scanf("%d", &tamanhoTurma);
  }
  while(tamanhoTurma <= 0 && tamanhoTurma >= 300);
  
  double notas[tamanhoTurma];
  
  int i;
  
  srand(time(0));
  
  for(i = 0; i < tamanhoTurma; i++) 
  {
    notas[i] = rand() % 11;
    
    printf("Nota do aluno %i: %.2lf.\n", i+1, notas[i]);
  }
}