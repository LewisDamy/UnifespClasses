
#include <stdio.h>

typedef int TChave;

typedef struct {
    TChave Chave;
    //Outros componentes
} TItem;

typedef struct SCelula *TApontador;

typedef struct SCelula {
    TItem Item;
    TApontador Prox;
} TCelula;

typedef struct {
    TApontador Frente, Tras;
    int Tamanho;
} TFila;

void TFila_Inicia(TFila *pFila)
{
    pFila->Frente = NULL;
    pFila->Tras = pFila->Frente;
    pFila->Tamanho = 0;
}

int TFila_EhVazia(TFila *pFila)
{
    return (pFila->Frente == NULL);
}

int TFila_Tamanho(TFila *pFila)
{
    return (pFila->Tamanho);
}

int Tfila_Enfileira(TFila *pFila, TItem x)
{
    TApontador pNovo;

    pNovo = (TApontador) malloc(sizeof(TCelula));
    pNovo->Item = x;
    pNovo->Prox = NULL;

    if(TFila_EhVazia(pFila))
        pFila->Frente = pNovo;
    else
        pFila->Tras->Prox = pNovo;
    
    pFila->Tras = pNovo;
    pFila->Tamanho++;
    return 1;
}

int Tfila_Desenfileira(TFila *pFila, TItem *pX)
{
    TApontador pAux;

    if (TFila_EhVazia(pFila))
        return 0;
    
    pAux = pFila->Frente;
    pFila->Frente = pAux->Prox;
    *pX = pAux->Item;
    free(pAux);
    pFila->Tamanho--;

    return 1;
}