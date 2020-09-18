//Area from an circle 

#include <stdio.h>
#include <math.h>

// exercise 6

int main(void) 
{
  double raio, area;
  
  printf("Entre com o raio do círculo: \n");
  scanf("%lf", &raio);
  
  area = pow(raio, 2.0) * M_PI;
  
  printf("A área do círculo é: %.2lf.\n", area);
}