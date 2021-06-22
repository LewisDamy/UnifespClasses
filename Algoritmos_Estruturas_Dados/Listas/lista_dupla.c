#include <stdio.h>

typedef int TChave;

typedef struct {
    TChave Chave;
} TItem;

typedef struct SCelula *TApontador;

typedef struct SCelula {
    TItem Item;
    TApontador Ant, Prox;
} TCelula;

typedef struct {
    TApontador Ultimo;
    int Tamanho;
} TLista;

void TLista_Inicia(TLista *pLista)
{
    //create head cell with Ultimo pointer control pointing at it
    pLista->Ultimo = (TApontador) malloc(sizeof(TCelula));
    //in the header cell the Prox space point at what the Ultimo pointer is pointing at aka point at the Ant pointer inside of the cell (point at other pointer inside of the cell)
    pLista->Ultimo->Prox = pLista->Ultimo;
    //se the ant pointer inside of the header cell to point at what Ultimo pointer is pointer at which is the Prox aka set the pointer to also point at ohter pointer inside of the cell
    pLista->Ultimo->Ant = pLista->Ultimo;
    //set the size variable to 0
    pLista->Tamanho = 0;
}

int TLista_EhVazia(TLista *pLista)
{
    return (pLista->Ultimo->Prox == pLista->Ultimo);
}

int TLista_Tamanho(TLista *pLista)
{
    return (pLista->Tamanho);
}

int TLista_Insere(TLista *pLista, TApontador p, TItem x)
{
    //create new pointer
    TApontador pNovo;

    //check if the pointer p is not pointing at null, if so, we cannot insert new cell
    if (p == NULL)
        return 0;
    
    //pNovo pointer will point at new cell with size TCelula by calling malloc
    pNovo = (TApontador) malloc(sizeof(TCelula));
    //set the info to where pNovo is pointing with is the space Item from the cell
    pNovo->Item = x;
    //the pointer pNovo which is pointing at Prox of the new cell set it equals to what p is pointing which is the next cell of the list
    pNovo->Prox = p;
    //the pointer pNovo which is pointing at Ant of the new cell to point at what p is pointing which is the Ant of the next cell of the list
    pNovo->Ant = p->Ant;
    //the pointer p which is pointing at Ant which is the "next new cell" and the Prox of the "old before cell" now are both pointing at the new middle cell (doubt see slides) 
    p->Ant->Prox = pNovo;
    
    //if  pointer Prox of the cell which p is pointing at is equals to what Ultimo pointer is pointing at which means it's the last cell of the list
    if (p->Ant == pLista->Ultimo)
        //set the Ultimo pointer control to point at the new last cell of the list
        pLista->Ultimo = pNovo;
    
    //set the new next cell Ant pointer to point at the new insert cell
    p->Ant = pNovo;
    //add 1 to the size variable
    pLista->Tamanho++;
    return 1;
}

int TLista_Retira(TLista *pLista, TApontador p, TItem *pX)
{
    //create new pointer
    TApontador pAux;

    //check if the list is not empty
    if (TLista_EhVazia(pLista))
        return 0;
    
    //set the pointer pAux to point at what p is pointing at which is the cell that we will remove
    pAux = p;
    //what p is pointing at which is the Ant pointer of the cell to be removed and that is pointing at the Prox pointer of the cell before
    //point that to what p is pointing at which is the Prox of the cell to be removed and taht is pointing at the Ant of the next cell
    //aka, summary set the Prox of the cell before to what we are removing to point at the Ant of the next cell that we are removing
    p->Ant->Prox = p->Prox;
    //what p is pointing which is the Prox of the cell that we are removing that Prox is pointing at the Ant of the cel after
    //point to waht p is pointing which is pointing at the Ant of the cell to be removed and taht is poinnting at the Prox of the cel before
    //aka, summary set the Ant of the cell after to what we are removing to point at the Prox of the cell before that we are reomving  
    p->Prox->Ant = p->Ant;

    //if the pAux pointer is pointing at the same that Ultimo is pointing at which would be the last element
    if (pAux == pLista->Ultimo)
        //set the pointer Ultimo control to point what p is pointing which is the Ant of the last cell that is pointing which is the prox of the head cell
        pLista->Ultimo = p->Ant;
    
    //save the info of what pAux is pointing at which is the Item of the cell that has been removed
    *pX = pAux->Item;
    //though away the pAux pointer
    free(pAux);
    //decrease by 1 the size control
    pLista->Tamanho--;
    return 1;
}

TApontador TLista_Retorna(TLista *pLista, int p)
{
    //create pointer
    TApontador pApontador;
    int Posicao;
    Posicao = 0;

    //set the new pointer to point at what Ultimo pointer control is pointing which is the last element and in that is the Prox is pointing at the head cell that is pointing at the first element of the cell
    pApontador = pLista->Ultimo->Prox->Prox;
    //keep looping while the pointer does not reach the Head cell again or if the it stops right before the value of p
    while ((pApontador != pLista->Ultimo->Prox) && (Posicao != p))
    {
        //set the pointer to point at what Prox of that cell is pointing which is the next cell
        pApontador = pApontador->Prox;
        //add 1 in position
        Posicao++;
    }
    
    return pApontador;
}