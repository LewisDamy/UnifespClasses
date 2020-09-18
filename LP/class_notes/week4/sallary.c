#include <stdio.h>
#include <math.h>

// exercício 8

int main() 
{
  double valor_hora, horas_trabalhadas, salario;
  
  printf("Entre com o valor da sua hora de trabalho: \n");
  scanf("%lf", &valor_hora);
  
  printf("Entre com o número de horas trabalhadas: \n");
  scanf("%lf", &horas_trabalhadas);
  
  salario = horas_trabalhadas * valor_hora;
  
  printf("O valor do salário é R$ %.2lf.\n", salario);
}