#include <stdio.h>
#include <stdlib.h>
#include<time.h> 

int main() 
{
  int dados[10], i, chave, achou = 0;
  
  srand(time(0));
  
  for(i = 0; i < 10; i++) 
  {
    dados[i] = rand() % 101 + 1;
    
    printf("dados[%d] = %d.\n", i, dados[i]);
  }

  printf("Entre com o número para ser buscado:\n");
  scanf("%d", &chave);

  for(i = 0; i < 10; i++) 
  {
    if(dados[i] == chave) 
    {
      printf("O número foi encontrado na posição %d.\n", i);
      achou = 1;
    } 
  }

  if(!achou) 
  {
    printf("O número não está no vetor.\n");
  }
}