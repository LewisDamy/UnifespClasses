#include <stdio.h>

// 4. Supondo que a população de um país A seja da ordem de 80000 habitantes com uma 
// taxa anual de crescimento de 3% e que a população de B seja 200000 habitantes com uma 
// taxa de crescimento de 1.5%. Faça um programa que calcule e escreva o número de anos necessários para que a 
// população do país A ultrapasse ou iguale a população do país B, mantidas as taxas de crescimento.
// 5. Altere o programa anterior permitindo ao usuário informar as populações e as taxas de crescimento iniciais. 
// Valide a entrada e permita repetir a operação.

int main() {
  int populacaoA, populacaoB;
  double taxaA, taxaB;

  do 
  {
    printf("Entre com a população do país A (número maior do que zero):\n");
    scanf("%d", &populacaoA);
  } 
  while(populacaoA <= 0);

  do 
  {
    printf("Entre com a população do país B (número maior do que zero e maior do que a população de A):\n");
    scanf("%d", &populacaoB);
  } 
  while(populacaoB <= 0 || populacaoB <= populacaoA);

  do 
  {
    printf("Entre com a taxa de crescimento de A:\n");
    scanf("%lf", &taxaA);
  } 
  while(taxaA <= 0);

  do 
  {
    printf("Entre com a taxa de crescimento de B:\n");
    scanf("%lf", &taxaB);
  } 
  while(taxaB <= 0);

  int anos = 0;

  while(populacaoA < populacaoB) 
  {
    populacaoA = populacaoA + (populacaoA * taxaA);
    populacaoB = populacaoB + (populacaoB * taxaB);
    anos++;
  }

  printf("População do país A: %d.\n", populacaoA);
  printf("População do país B: %d.\n", populacaoB);
  printf("Passaram-se %d anos até que a população de A passasse ou igualasse a população de B.\n", anos);
}