#include <stdio.h>
#include <stdlib.h>

typedef int TChave;

typedef struct {
    TChave Chave;
} TItem;

typedef struct SCelula *TApontador;

typedef struct SCelula {
    TItem Item; //type item that has an item
    TApontador Prox; //pointer to the next cell 
} TCelula;

typedef struct {
    TApontador Primeiro, Ultimo; //two pointers, first and last pointers
    int Tamanho; //variable that is a type int to keep track of the size
} TLista;

//-------------------------OPERATIONS--------------------------------------------

void TLista_Inicia(TLista *pLista)
{
    //set the list, aka, the first and last pointers to null and the size variable to 0
    pLista->Primeiro = NULL;
    pLista->Ultimo = pLista->Primeiro;
    pLista->Tamanho = 0;
}

int TLista_EhVazia(TLista *pLista)
{
    //if the first pointer to the list is equal to null then, the list is empty
    return (pLista->Primeiro == NULL);
}

int TLista_Tamanho(TLista *pLista)
{
    //return the integer size
    return (pLista->Tamanho);
}

//function to know an "p" location
TApontador Tlista_Retorna(TLista *pLIsta, int p)
{
    //define another type pointer
    TApontador pApontador;
    //define an integer called position
    int Posicao;
    //set poisition to 0
    Posicao = 0;
    //the new pointer will point to the fist pointer of the list
    pApontador = pLista->Primeiro;
    //keep looping while the new pointer isn't null or the position variable is equal to "p" (the asked position)
    while((pApontador != NULL) && (Posicao != p)) {
        //set the new pointer to the prox pointer of an cell pointer
        pApontador = pApontador->Prox;
        //add 1 to the position
        Posicao++;
    }
    //return the pointer of the location of the cell that is in the p-th position
    return pApontador;
}

int TLista_InserePrimeiro(TLista *pLista, TItem x)
{
    //create new type pointer
    TApontador pNovo;

    //allocate the proper space for the new TCelula(composed of space for info, aka Item and the prox, aka pointer) with malloc
    pNovo = (TApontador) malloc(sizeof(TCelula));
    //set the type Item in the new TCelula with the new info x
    pNovo->Item = x;
    //set the type prox of the new TCelula with the fist pointer of the list
    pNovo->Prox = pLista->Primeiro;
    //check if the list is empty, if so, then set the last pointer to be the new pointer
    if (TLista_EhVazia(pLista))
        pLista->Ultimo = pNovo;
    //set the control first pointer of the list to be pointing to the first new cell (pNovo)
    pLista->Primeiro = pNovo;
    //add 1 to the size
    pLista->Tamanho++;
    return 1;
}

int TLista_InsereUltimo(TLista *pLista, TItem x)
{
    //create new type ponter
    TApontador pNovo;

    //allocate the proper space for the new TCelula(composed of space for info, aka Item and the prox, aka pointer) with malloc
    pNovo = (TApontador) malloc(sizeof(TCelula));
    //set the type Item in the new TCelula with the new info x
    pNovo->Item = x;
    //set the type prox (pointer) to null 'cause it will be the new end of the list
    pNovo->Prox = NULL;

    //check if the list is empty, if so, then set the first pointer to be the new pointer
    if (TLista_EhVazia(pLista))
        pLista->Primeiro = pNovo;
    //if not, set the last prox in TCelula to point to the new pointer (this new is already pointing to NULL)
    else
        pLista->Ultimo->Prox = pNovo;
    //change the control last pointer to point to the new cell (pNovo) 'cause is new the new last item  
    pLista->Ultimo = pNovo;
    //add 1 to the size
    pLista->Tamanho++;
    return 1;
}

int TLista_Insere(TLista *pLista, TApontador p, TItem x)
{
    //create two pointers the before and new, just like the draw in notebook
    TApontador pAnterior, pNovo;

    //if the location of the new cell (p) is in the first location of the list, then use the function ...
    if (p == pLista->Primeiro)
        return TLista_InserePrimeiro(pLista, x);
    //if the location of the new cell (p) is in the last location of the list, then use the function ...
    else if (p == NULL)
        return TLista_InsereUltimo(pLista, x);
    //else, aka, if you want to add in the anywhere in the line, besides the first and last location, then
    else {
        //set the anterior pointer to be the first item in the list and interate
        pAnterior = pLista->Primeiro;
        //while the pointer anterior does not find the last pointer of the last cell in the list, or the p-th location keep looping
        while ((pAnterior != pLista->Ultimo) && (pAnterior->Prox != p))
            //once found the correct location to insert the new cell, point the Anterior pointer to the prior cell to be add to point to the prox of that cell
            pAnterior = pAnterior->Prox;
        //check if the pAnterior cell is not pointing to the null pointer of the last cell, if so, return 0 (something went wrong)
        if (pAnterior == pLista->Ultimo)
            return 0;
        
        //allocate the proper space for the new TCelula(composed of space for info, aka Item and the prox, aka pointer) with malloc
        pNovo = (TApontador) malloc(sizeof(TCelula)); 
        //set the item location to have the x information
        pNovo->Item = x;
        //point the Prox in Tcelula to point to the next cell of the line that were pointed by the pAnterior
        pNovo->Prox = pAnterior->Prox;
        //add 1 to the size variable
        pLista->Tamanho++;
        return 1;
    }
}

int TLista_RetiraPrimeiro(TLista *pLista, TItem *pX)
{
    //create new pointer 
    TApontador pAux;

    //check if the list is empty, if so, then return 0 (something went wrong)
    if (TLista_EhVazia(pLista))
        return 0;

    //set pAux to point to the pointer first of the list
    pAux = pLista->Primeiro;
    //set the pointer control first of the list to point to the right next cell'pointer
    pLista->Primeiro = pAux->Prox;
    //take the info of in the Item TCell location and save it in pX aka (remove the info from the cell)
    *pX = pAux->Item;
    //free, aka though away the auxiliar pointer, we don't need anymore
    free(pAux);
    //decrease by 1 the size of the list
    pLista->Tamanho--;
    return 1;
}

int TLista_RetiraUltimo(TLista *pLista, TItem *pX)
{
    //create two new pointers
    TApontador pAnterior, pAux;

    //pAnterior pointer, point to the first control pointer
    pAnterior = pLista->Primeiro;
    //check if the new pAnterior is not pointing to the last pointer of the list, 'cause if so, then it's the first element, and use the function ...
    if (pAnterior == pLista->Ultimo)
        return TLista_RetiraPrimeiro(pLista, pX)
    //else, aka if not the if statement, you are good to go (remove the last element)
    else {
        //keep looping while the pointer pAnterior find the last pointer control
        while (pAnterior->Prox != pLista->Ultimo)
            //once found, set the pointer pAnterior to the successor of the last, aka the penultimum cell'prox
            pAnterior = pAnterior->Prox;
        
        //set the pAux poninter to the last cell of the list
        pAux = pLista->Ultimo;
        //define in the TCelula successor of the last, the pointer in that cell to be null 
        pAnterior->Prox = NULL;
        //change the last pointer control to point to this sucessor of the last, that eventually will be the last
        pLista->Ultimo = pAnterior;
        //save the info in the last cell into the x spot
        *pX = pAux->Item;
        //though away the pointer aux, we don't need anymore
        free(pAux);
        //decrease by 1 the size o the list
        pLista->Tamanho--;
        return 1;
    }
}

int TLista_Retira(TLista *pLista, TApontador p, TItem *pX)
{
    //create two pointers
    TApontador pAnterior, pAux;

    //check if the location to remove (p) is the fist on the list, if so, use the function...
    if (p == pLista->Primeiro)
        return TLista_RetiraPrimeiro(pLista, pX);
    //check also if the location to remove (p) is the last on the list, if so, use the function..
    else if (p == pLista->Ultimo)
        return TLista_RetiraUltimo(pLista, pX);
    //else, aka, if you want to remove anywhere in the line, besides the first and last location, then
    else {
        //set the pAnterior pointer to be pointing to the first control pointer of the list
        pAnterior = pLista->Primeiro;
        //keep looping until the pointer is not in the last pointer location of the list or if the pointer is not the one that p is located (doubt see the notebook)
        while ((pAnterior != pLista->Ultimo) && (pAnterior->Prox != p))
            //set the pAnterior pointer to be the pre-sucessor of the cell that you want to remove
            pAnterior = pAnterior->Prox;
        //if that pointer is the last something went wrong
        if (pAnterior == pLista->Ultimo)
            return 0;

        //set the pointer pAux to point into the right-next after the p-th location 
        pAux = pAnterior->Prox;
        //set the pointer pAnterior to point to the prox in the TCell right left the cell that will be gone
        pAnterior->Prox;
     //set the pointer of the TCell that has a pAnterior pointing on to point to the next cell (relocate the prox pointer 'cause the right after will be gone)
        pAnterior->Prox = pAux->Prox;
        //realocate the info that were in the TCell space that has the pAux pointing on to save into the x location
        *pX = pAux->Item;
        //though away the pointer pAux, we have already remove the cell
        free(pAux);
        //decrease by 1 the size of the list
        pLista->Tamanho--;
        return 1;
    }

}









//----------------ANOTHER WAY TO INSERT IN LISTS---------------------------------------
int TLista_Insere2(TLista *pLista, int p, TItem x)
{
    TApontador pAnterior, pNovo;
    int i;

    if (p == 1)
        return TLista_InserePrimeiro(pLista, x);
    else if (p == TLista_Tamanho(pLista))
        return TLista_InsereUltimo(pLista, x);
    else if (p < 0) || (p > TLista_Tamanho(pLista))
        return 0;
    else {
        i = 2;
        pAnterior = pLista->Primeiro;
        while (i != p) {
            pAnterior = pAnterior->Prox;
            i++;
        }

        pNovo = (TApontador) malloc(sizeof(TCelula));
        pNovo->Item = x;
        pNovo->Prox = pAnterior->Prox;
        pAnterior->Prox = pNovo;
        pLista->Tamanho++;
        return 1;
    }
}


//---------------------------------------------------------------------------------------------