#include <stdio.h>

//Defining the max size of the stack
#define MAXTAM 1000


//Creating an integer called TApontador which will point to the last item of the stack
typedef int TApontador;

//Defining the structure of the stack, it has the top max items notated by 1000 and the integer TApontador
typedef struct {
    float Item [MAXTAM];
    TApontador Topo;
 } TPilha;

//functions and procedures, we will pass it by reference

//NOTE: Those functions will return an integer, 0 if something went wrong or another thing if works

//inicialize the stack with a pointer
void TPilha_Inicia(TPilha *pPilha)
{
    //making sure that the Topo is inicialized with 0
    pPilha->Topo = 0;
}

int TPilha_EhVazia(TPilha *pPilha)
{
    //test if it's empty if so, return 0 or not return 1 or other number
    return (pPilha->Topo == 0);
}

int TPilha_Empilha(TPilha *pPilha, float x)
{
    //check if Topo is pointing to the max size, if so, return 0 meaning that it's full, does not accept more stacking
    if (pPilha->Topo == MAXTAM)
        return 0;

    //if not full, add stack to the Item[i] where i is the top of the stack,aka where pPilha->Topo
    pPilha->Item[pPilha->Topo] = x;
    //Add to the variable Topo 1, so that it knows that one more item were added
    pPilha->Topo++;
    return 1; //work with success
}

int TPilha_Desempilha(TPilha *pPilha, float *pX)
{
    //check if the stack is empty
    if (TPilha_EhVazia(pPilha))
        return 0; 
    
    //decrement by 1 the Topo beforewards removing the last element
    pPilha->Topo--;
    //save the pX as point to the new Topo variable
    *pX = pPilha->Item[pPilha->Topo];
    return 1; //everything went good

}

int TPilha_Tamanho(TPilha *pPilha)
{
    //print the size of it
    return (pPilha->Topo);
}