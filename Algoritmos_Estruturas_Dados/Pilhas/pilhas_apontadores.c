#include <stdio.h>

//pointer to SCelula
typedef struct SCelula *TApontador;

//TCelula has an item, an pointer
typedef struct SCelula {
    float Item;
    TApontador Prox;
} TCelula;

//TPilha has an pointer to the top and an integer to the size of the stack
typedef struct {

    TApontador Topo;
    int Tamanho;
} TPilha;

void TPilha_Inicia(TPilha *pPilha)
{
    pPilha->Topo = NULL;
    pPilha->Tamanho = 0;
}

int TPilha_EhVazia(TPilha *pPilha)
{
    return (pPilha->Topo == NULL);
}

int TPilha_Tamanho(TPilha *pPilha)
{
    return (pPilha->Tamanho);
}

int TPilha_Empilha(TPilha *pPilha, float x)
{
    //create new pointer
    TApontador pNovo;
    //request new space in memory by creating new cell
    pNovo = (TApontador) malloc(sizeof(TCelula));
    //add the new item x in the new cell
    pNovo->Item = x;
    //point the new cell to the pointer of the last in the stack
    pNovo->Prox = pPilha->Topo;
    //point the top pointer to the new cell
    pPilha->Topo = pNovo;
    //increment the new size of it
    pPilha->Tamanho++;
    //printf("Empilha: %i\n", pPilha);
    return 1;
}

int TPilha_Desempilha(TPilha *pPilha, float *pX)
{
    //create new pointer aux
    TApontador pAux;

    //check if the stack is empty, if don't do it
    if (TPilha_EhVazia(pPilha))
        return 0;
    
    //the pointer aux is going to point to the top of the stack
    pAux = pPilha->Topo;
    //the new top is going to be pointing to the aux pointer
    pPilha->Topo = pAux->Prox;
    //add the value x by referencing where it is w/ * and saving to the item inside of the stack struct 
    *pX = pAux->Item;
    //free memory of aux
    free(pAux);
    //decrease size of the stack
    pPilha->Tamanho--;
    return 1;
}
