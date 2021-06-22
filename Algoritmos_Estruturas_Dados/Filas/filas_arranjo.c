#include <stdio.h>

#define MAXTAM 32770

typedef int TApontador;


typedef struct {
    int Pinicial;
    int Patual;
    int index;
} TFighter;

typedef struct {
    //Set the array Items with the limit 1000
    TFighter Item[MAXTAM];
    //Set the pointers Front and Back
    TApontador Frente, Tras;
} TFila;

//Functions and procedures for TAD 

void TFila_Inicia(TFila *pFila);
int TFila_EhVazia(TFila *pFila);
int TFila_Enfileira(TFila *pFila, TFighter x);
int TFIla_Desenfileira(TFila *pFila, TFighter *pX);
int TFila_Tamanho(TFila *pFila);

//Functions

void TFila_Inicia(TFila *pFila)
{
    //Initialize the pointer from the Front of the line
    pFila->Frente = 0;
    //Initialize the pointer from the Back of the Line
    pFila->Tras = 0;
}

int TFila_EhVazia(TFila *pFila)
{
    //Check if the Front and Back of the Line are equal
    return(pFila->Frente == pFila->Tras);
} 

int TFila_Tamanho (TFila *pFila)
{
    //if the Back of the Line is greater than or equal to the Front (TRUE == ?) DO the subtraction (Back - Front) to know the size of it
    //else if the Back of the Line is less than the Front (FALSE == :) DO (MAXTAM + Back - Front)
    return((pFila->Tras >= pFila->Frente) ?
            (pFila->Tras - pFila->Frente) :
            (MAXTAM + pFila->Tras - pFila->Frente));
}

int TFila_Enfileira(TFila *pFila, TFighter x) 
{
    //if the Front is equal to the Back + 1(the gap space) we reach the MAXTAM
    //aka the next Front would be the Back (NOT RIGHT)
    if (pFila->Frente == (pFila->Tras + 1) % MAXTAM) //remaining of the division "%" for instance if the Front of the line is greater than the Back + 1 don't do it
        // The line is full
        return 0;

    //set the Line item[Back] = x value
    pFila->Item[pFila->Tras] = x;
     //printf("Enfileirou: %i\n", x);
    // if the Back of the Line is less than the Back + 1 and are less of the max size of the line "%"
    pFila->Tras = (pFila->Tras + 1) % MAXTAM;
    return 1;
}

int TFila_Desenfileira(TFila *pFila, TFighter *pX) 
{
    //check if the Line is empty
    if (TFila_EhVazia(pFila))
        //if so, don't Add
        return 0;
    //pass the location of the x (by reference) to the Front of the line
    *pX = pFila->Item[pFila->Frente];
    //set the new front of the Line  and add 1  
    pFila->Frente = (pFila->Frente + 1) % MAXTAM;
    //printf("Desenfileira: %i", x);
    return 1;
}
