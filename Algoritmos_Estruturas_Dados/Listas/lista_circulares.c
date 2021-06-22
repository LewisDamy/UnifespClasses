//Lista Circular

typedef int TChave;

typedef struct {
    TChave Chave;
} TItem;

typedef struct SCelula *TApontador;

typedef struct SCelula {
    TItem Item;
    TApontador Prox;
} TCelula;

typedef struct {
    TApontador Ultimo;
    int Tamanho;
} TLista;

//____________________FUNCOES__________________________________________

void TLista_Inicia(TLista *pLista)
{
    //create the head cell with malloc
    pLista->Ultimo = (TApontador) malloc(sizeof(TCelula));
    //set the head pointer to what the ultimo pointer control is pointing, aka, point the itself
    pLista->Ultimo->Prox = pLista->Ultimo;
    //set the size variable of the list to 0
    pLista->Tamanho = 0;
}

int TLista_EhVazia(TLista *pLista)
{
    //check if the Ultimo pointing in the list is the same as the ultimo pointer control
    return (pLista->Ultimo->Prox == pLista->Ultimo);
}

int TLista_Tamanho(TLista *pLista)
{
    //return the variable size in the list
    return (pLista->Tamanho);
}

int TLista_Insere(TLista *pLista, TApontador p, TItem x)
{
    //create two new pointers
    TApontador pAnterior, pNovo;
    //set the pAnterior pointing to where teh last cell ins pointing which is the head cell pointer
    pAnterior = pLista->Ultimo->Prox;

    //keep looping while the pAnterior hasn't reach the end of the line or if the the pointing is not where p is pointing at (which where the right cell where it will be insert)
    while ((pAnterior != pLista->Ultimo) && (pAnterior->Prox != p))
        //set the pointer pAnterior to point at the next prox pointer in each cell
        pAnterior = pAnterior->Prox;
    
    if (pAnterior->Prox != p)
        return 0;

    //create new space in memory as the size of a Cell and set the pNovo pointer to point at it
    pNovo = (TApontador) malloc(sizeof(TCelula));

    //insert the info into the Item part of the cell
    pNovo->Item = x;
    //set where pNovo is pointing which is the new cell to point at where pAnterior is pointing which is an cell of the list
    pNovo->Prox = pAnterior->Prox;
    //set where pAnterior is pointing which is the cell in the list to point where pNovo is pointing which is the new cell, aka the cell in the list now points to the new one
    pAnterior->Prox = pNovo;

    // if the pAnterior pointer is pointing at the same element that the ultimo pointer control is, then that is an insertion at the end of the cell
    if(pAnterior == pLista->Ultimo)
        // set the ultimo pointer controll to point to the new last element
        pLista->Ultimo = pNovo;
    
    //increment by 1 the size control
    pLista->Tamanho++;
    return 1;
}

int TLista_Retira(TLista *pLista, TApontador p, TItem *pX)
{
    //create two new pointers
    TApontador pAnterior, pAux;

    //check if the list is empty, stop the program
    if (TLista_EhVazia(pLista))
        return 0;
    
    //set the pointer pAnterior to point to the next what the Ultimo pointer is pointing at which is the last element, so point at what the last element is pointing which is the head cell
    pAnterior = pLista->Ultimo->Prox;

    //keep looping while the pAnterior hasn't reach the end of the line or if the the pointing is not where p is pointing at (which where the right cell where it will be removed)
    while ((pAnterior != pLista->Ultimo) && (pAnterior->Prox != p))
        //set the pointer pAnterior to point at the next cell pointer
        pAnterior = pAnterior->Prox;
    
    
    if (pAnterior->Prox != p)
        return 0;
    
    //set pointer pAux to pointer the next cell that pAnterior is pointing at, which will be the cell to be removed
    pAux = pAnterior->Prox;
    //set the what pAnterior is pointing at which is the cell before the one that has been removed to point at the next cell that pAux is pointing at which is the cell that the removed cell was pointing at
    pAnterior->Prox = pAux->Prox;

    //if the pAux is the pointing at the same thing which Ultimo pointer controll is pointing at means that it's the end of the list
    if (pAux == pLista->Ultimo)
        //set the Ultimo pointer to point at the new last element of the cell
        pLista->Ultimo = pAnterior;
    
    //save the info of the cell that pAux is pointing which is the one that we are removing
    *pX = pAux->Item;
    //though away the pAux pointer
    free(pAux);
    //decrease by 1 the size list control
    pLista->Tamanho--;
    return 1;
}

TApontador TLista_Retorna(TLista *pLista, int p)
{
    //create new ponter
    TApontador pApontador;

    int Posicao;
    Posicao = 0;
    
    //set the new pointer to point at what ultimo pointer control is pointing which is the head cell and point also where the head cell is pointing which is the first element of the list
    pApontador = pLista->Ultimo->Prox->Prox;

   //keep looping if this pointer pApontador is not what the Ultimo pointer control is pointing at which is the head list aka loop though the entire list 
   // or if the position is not p aka, stop right before the p-th position is pointing at 
    while ((pApontador != pLista->Ultimo->Prox) && (Posicao != p))
    {
        //move the pointer to the next cell
        pApontador = pApontador->Prox;
        //add 1 
        Posicao++;
    }
    //return the location i-th by passing the pointer to that cell
    return pApontador;
}
