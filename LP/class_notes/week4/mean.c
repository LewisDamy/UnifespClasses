#include <stdio.h>

int main() 
{
  double soma = 0.0, num, media = 0.0;
  int num_lidos = 0;
  
  printf("Programa de cálculo de média.\n");
  
  printf("Digite o primeiro número da sequência:\n");
  scanf("%lf", &num);
  
  while(num != -1) 
  {
    soma += num;
    num_lidos++;
    
    printf("Digite o próximo número ou -1 para terminar a leitura.\n");
    scanf("%lf", &num);
  }
  if(num_lidos != 0) 
  {
    media = soma / num_lidos;
    
    printf("A média é: %.2lf.\n", media);
  }
}