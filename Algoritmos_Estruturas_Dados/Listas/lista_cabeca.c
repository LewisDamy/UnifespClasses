//Listas com Cabeca (Head)

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
    TApontador Primeiro, Ultimo;
    int Tamanho;
} TLista;

//_____________FUNCOES___________________________________________

void TLista_Inicia(TLista *pLista)
{
    //allocate space of the head cell with the primeiro control pointer pointing to it
    pLista->Primeiro = (TApontador) malloc(sizeof(TCelula));
    //Ultimo control pointer set to the head pointer
    pLista->Ultimo = pLista->Primeiro;
    //set the head pointer to be null 
    pLista->Primeiro->Prox = NULL;
    //set the size control to 0
    pLista->Tamanho = 0;
}

int TLista_EhVazia(TLista *pLista)
{
    //if the primeiro pointer is pointing to the same location as the ultimo pointer, which can only happen when we only have the head cell that is pointing to null
    //return 1 
    return (pLista->Primeiro == pLista->Ultimo);
}

int TLista_Insere(TLista *pLista, TApontador p, TItem x)
{
    //create 2 pointers 
    TApontador pAnterior, pNovo;

    //set the pointer pAnterior to point to the pointer Primeiro which is pointing to the head cell pointer
    pAnterior = pLista->Primeiro;
    //interate through the list, until the pointer pAnterior is not pointing to the null cell and is not where the pointer in pointing at 
    while((pAnterior != pLista->Ultimo) && (pAnterior->Prox != p))
        //keep moving the pAnterior pointer until it reach the proper place to add the new cell
        pAnterior = pAnterior->Prox;
    //if the pAnterior pointer is pointing to the right location and is different than the pointer p, something went wrong
    if(pAnterior->Prox != p)
        return 0;
    //create new pointer that is pointing to a new cell 
    pNovo = (TApontador) malloc(sizeof(TCelula));
    //take the information and save it in the item' cell location
    pNovo->Item = x;
    //the pointer pNovo that is pointing to the new cell now points to the pointer that is pointing to the list cell
    pNovo->Prox = pAnterior->Prox;
    //the pointer of the list cell points now to what the pNovo is pointing which is the new cell
    pAnterior->Prox = pNovo;
    
    //if the cell that you want to add is the first one, aka, there is only one cell
    if (pAnterior == pLista->Ultimo)
        //the ultimo control cell points to the new (only) cell 
        pLista->Ultimo = pNovo;
    //add 1 to the size counter
    pLista->Tamanho++;
    return 1;
}

int TLista_Retira(TLista *pLista, TApontador p, TItem *pX)
{
    //create pointers
    TApontador pAnterior, pAux;

    //set the pointer pAnterior to point where the Primeiro pointer is pointing which is the head cell
    pAnterior = pLista->Primeiro;

    //keep looping until the pointer is not in the last pointer location of the list or if the pointer is not the one that p is located 
    while ((pAnterior != pLista->Ultimo) && (pAnterior->Prox != p));
        //set the pAnterior pointer to be the pre-sucessor of the cell that you want to remove
        pAnterior = pAnterior->Prox;
    
    //if the ponter pAnterior is not pointing where p is pointing (in order to remove it) something went wrong
    if (pAnterior->Prox != p)
        return 0;
    
    //set the pAux pointer to point where the pAnterior is pointing 
    pAux = pAnterior->Prox;

    //set the cell before the one that we are removing to point where the new one, the one that the Aux is pointing
    pAnterior->Prox = pAux->Prox;
    
    //check if the pointer pAux is pointing to the same location as the ultimo pointer controll, which will means that it's the last cell of the list
    if (pAux == pLista->Ultimo)
        //set the ulitmo pionter control to be the new panterior last cell of the list
        pLista->Ultimo == pAnterior;
    
    //fsave the info in the cell that we are removing to x
    *pX = pAux->Item;
    //though away the pAux pointer
    free(pAux);
    //decrease by one the size 
    pLista->Tamanho--;
    return 1;
}

TApontador TLista_Lista_Retorna(TLista *pLista, int p)
{
    //create new pointer
    TApontador pApontador;
    //create integer
    int Posicao;
    //set integer to 0
    Posicao = 0; 
    //set the pointer pApontador to point to the Primeiro pointer controll which is pointing to the head pointer cell
    pApontador = pLista->Primeiro->Prox;

    while((pApontador != NULL) && (Posicao != p)){
        pApontador = pApontador->Prox;
        Posicao++;
    }
    //return the pointer that is pointing to where we found the location of the item
    return pApontador;
}

