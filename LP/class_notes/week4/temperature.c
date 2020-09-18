#include <stdio.h>

// exercício 9

int main(void) 
{
  double farenheit;
  int celsius;
  char o;
  
  printf("Entre com a temperatura em Farenheit:\n");
  scanf("%lf", &farenheit);
  
  celsius = 5.0 * ((farenheit-32.0) / 9.0);
  o = 167;
  
  printf("A temperatura em Celsius é %i%c.\n", celsius, o);
}