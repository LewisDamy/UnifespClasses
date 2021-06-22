
#include <stdio.h>
#include<stdlib.h>

#define INICIO 0
#define MAXTAM 1000

typedef int TChave;
//notice that the pointer to the list is an INTEGER
typedef int TApontador;

//define the item of the list
typedef struct {
    TChave Chave;
} TItem;

//define the struct list, that has an array of type Item with size MAXTAM
// also has two pointers of type INTEGER that will point to the first and last item of the list
typedef struct {
    TItem Item[MAXTAM];
    TApontador Primeiro, Ultimo;
} TLista;

//----------------------------------procedures and functions of TAD-----------------------------------------------

void TLista_Inicia(TLista *pLista); //inicialize the list passing by reference the location of the list


int TLista_EhVazia(TLista *pLista); //checking if the list in empty passing also by reference the location of the list

int TLista_Insere(TLista *pLista, TApontador p, TItem x); 
//pass by reference the location of the list
//pass the position of the pointer (TYPE INT) called p 
//pass the item to be added in the list

int TLista_Retira(TLista *pLista, TApontador p, TItem *pX);
//pass by reference the location of the list
//pass the position of the pointer (TYPE INT) called p 
//pass by reference the location of the item to be removed from the list

int TLista_Tamanho(TLista *pLista); //check the size of the list passing by reference the location of the list


//------------------------------------------------FUNCTIONS----------------------------------------------------

void TLista_Inicia(TLista *pLista)
{
    //take list and set the pointer FIRST (type INT) to the value of INICIO which is 0
    pLista->Primeiro = INICIO;
    // take list and set another pointer LAST (type INT) equals to the pointer FIRST
    pLista->Ultimo = pLista->Primeiro;
}

int TLista_EhVazia(TLista *pLista)
{
    //return an int that check if the pointer FIRST is equal to the pointer LAST notice both are connected to the list
    return (pLista->Primeiro == pLista->Ultimo);
}



int TLista_Insere(TLista *pLista, TApontador p, TItem x)
{
    //create another pointer (type int)
    TApontador q;

    //check if the last pointer of the list is equal to the maxtam OR 
    // if the PLACE OF INSERTION p is less than the first pointer (don't do it) OR
    // if the PLACE OF INSERTION p is greater than the last pointer (don't do it)
    if ((pLista->Ultimo == MAXTAM) || 
        (p < pLista->Primeiro) ||
        (p > pLista->Ultimo))
        return 0;
    
    //interate though the list, set the new pointer q to be the penultimate of the list, and until q is greater than the pointer p, keep subtracting
    for (q = pLista->Ultimo - 1; q >= p; q--)
        //set the itens of the list to be the ONE more that it was;
        pLista->Item[q+1] = pLista->Item[q];
    //insert the value x of type item to the p-th position in the list
    pLista->Item[p] = x;
    // increment by one the last pointer
    pLista->Ultimo++;
    return 1;
}


int TLista_Retira(TLista *pLista, TApontador p, TItem *pX)
{
    //create new pointer (type int)
    TApontador q;

    //check if the list is empty OR 
    //if the PLACE OF REMOTION is less than the first pointer (don't do it) OR
    //if the PLACE OF REMOTION is greater than the last pointer (don't do it)
    if (TLista_EhVazia(pLista) ||
        (p < pLista->Primeiro) ||
        (p >= pLista->Ultimo))
        return 0;
    
    //pass by reference the location of the value x and insert in the  p-th position of the list
    *pX = pLista->Item[p];

    //interate though the list, set the new pointer q to be the next-door of the p pointer, and until the last pointer is greater than the pointer q, keep adding
    for (q = p + 1; q < pLista->Ultimo; q++)
        //set the antecessor of the the q pointer to be the new q pointer aka jump one location tho the left 
        pLista->Item[q-1] = pLista->Item[q];
    
    //decrease by one the last pointer
    pLista->Ultimo--;
    return 1;
}



int TLista_Tamanho(TLista *pLista)
{
    //return an int that will indicate the subtraction of the pointer LAST (type int) to the pointer FIRST (type int)
    return (pLista->Ultimo - pLista->Primeiro);
    //that will give an integer of the size of our list
}
