// Grades mean calculation

#include <stdio.h>

int main(void) 
{
  double soma = 0.0, nota, media = 0.0;
  int i;
  
  for(i = 1; i <= 4; i++) 
  {
    printf("Type the %i° grade:\n", i);
    scanf("%lf", &nota);
    
    soma += nota;
  }
  
  media = soma / 4.0;
  
  printf("The mean from the student is %.2lf\n", media);
}