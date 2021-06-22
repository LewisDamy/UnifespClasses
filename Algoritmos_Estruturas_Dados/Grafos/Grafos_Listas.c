#include <stdio.h>
#include <stdlib.h>

#define MAXVERTICES 100
#define INICIO 0
#define MAXTAM 1000

//notice that the pointer to the list is an INTEGER
typedef int TApontador;

//define the struct list, that has an array of type Item with size MAXTAM
// also has two pointers of type INTEGER that will point to the first and last item of the list
typedef struct {
    int Item[MAXTAM];
    TApontador Primeiro, Ultimo;
} TLista;

typedef int TVertice;

typedef int TAresta;

typedef struct {
    int Vertice;
    int Aresta;
}  TAdjacencia;

typedef struct {
    TLista Adj [MAXVERTICES];
    int NVertices;
    int NArestas;
} TGrafo;

//_START FUNCTIONS LISTS___________________

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



int TLista_Insere(TLista *pLista, TApontador p, TAdjacencia x)
{
    //create another pointer (type int)
    TApontador q;

    //check if the last pointer of the list is equal to the maxtam OR 
    // if the PLACE OF INSERTION p is less than the first pointer (don't do it) OR
    // if the PLACE OF INSERTION p is greater than the last pointer (don't do it)
    //if ((pLista->Ultimo == MAXTAM) || (p < pLista->Primeiro) || (p > pLista->Ultimo))
    //    return 0;
    
    //interate though the list, set the new pointer q to be the penultimate of the list, and until q is greater than the pointer p, keep subtracting
    for (q = pLista->Ultimo - 1; q >= p; q--)
        //set the itens of the list to be the ONE more that it was;
        pLista->Item[q+1] = pLista->Item[q];
    //insert the value x of type item to the p-th position in the list
    pLista->Item[p] = x.Vertice;
    // increment by one the last pointer
    pLista->Ultimo++;
    return 1;
}


int TLista_Retira(TLista *pLista, TApontador p, TAdjacencia *pX)
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
    pX->Aresta = pLista->Item[p];

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


//---------------------_GRAFOS__FUNCOES-------------------------------------------------------------------------------------------------------

int TGrafo_Inicia (TGrafo *pGrafo, int NVertices)
{
    TVertice u;

    //check if there are still available space
    if (NVertices > MAXVERTICES)
        return 0;

    //set the NVertices control to be the one that the user wants to create a new graph
    pGrafo->NVertices = NVertices;
    //set the NArestas control to be 0 (no arestas were add until now)
    pGrafo->NArestas = 0;

    //iterate though the array Adj[u] in which u is an type TVertice and will interate until the int NVertices were given by the user
    for (u = 0; u < pGrafo->NVertices; u++)
        //create a list to each cell of the array 
        TLista_Inicia (&pGrafo->Adj[u]);
    
    return 1;
}

int TGrafo_ExisteAresta (TGrafo *pGrafo, TVertice u, TVertice v)
{
    //create an int Vertice and Aresta contaned in type TAdjacencia
    TAdjacencia Adj;
    //create an list 
    TLista ListaAdj;
    int Existe;
    Existe = 0;
    //inicialize list
    TLista_Inicia(&ListaAdj);
    //keep doing while you finishied removing all of the elements from the array's list
    while (TLista_Retira(&pGrafo->Adj[u], TLista_Tamanho(&pGrafo->Adj[u]) - 1, &Adj))
    {
        //insert this elements into a temporary list 
        TLista_Insere(&ListaAdj, TLista_Tamanho(&ListaAdj), Adj);
        //save the info where Adj is been looping if there is an aresta in the vertice
        Existe = (Adj.Vertice == v);
        // ??
        if (Existe)
            break;
    }
    //while the list temporary is  not empty, keep doing
    while (TLista_Retira(&ListaAdj, TLista_Tamanho(&ListaAdj) - 1, &Adj))
        //insert back into the pGrafo the list of the respectively array'list items
        TLista_Insere(&pGrafo->Adj[u], TLista_Tamanho(&pGrafo->Adj[u]), Adj);
    
    return (Existe);
}

int TGrafo_InsereAresta(TGrafo *pGrafo, TVertice u, TVertice v, TAresta e)
{
    int i;
    //create a type TAdjacencia which has an .Vertice and .Aresta
    TAdjacencia Adj;
    //save the user'input vertice to the .vertice
    Adj.Vertice = v;
    //save the user'input aresta to the .aresta
    Adj.Aresta = e;
    //check if this insertion on the list proper insert
    if (TLista_Insere(&pGrafo->Adj[u], TLista_Tamanho(&pGrafo->Adj[u]), Adj))
    {
        //if so, add to the NArestas control
        pGrafo->NArestas++;
        return 1;
    }
    else
        return 0;
}

int TGrafo_RetiraAresta (TGrafo *pGrafo, TVertice u, TVertice v, TAresta *pE)
{
    //create list
    TLista ListaAdj;
    //create adj.vertice and adj.aresta type (int)
    TAdjacencia Adj;
    int IncideAresta;

    IncideAresta = 0;
    //inicialize list
    TLista_Inicia(&ListaAdj);
    //keep looping until IncideAresta equals to 1 or the function remove from list is less than 1 from what it was
    while (!IncideAresta && TLista_Retira(&pGrafo->Adj[u], TLista_Tamanho(&pGrafo->Adj[u]) - 1, &Adj))
    {
        //check if the .vertice is the same that the user wants us to remove
        if (Adj.Vertice == v)
        {
            //if so, save the info
            *pE = Adj.Aresta;
            //decrease by one the size control of arestas in our graph
            pGrafo->NArestas--;
            //set the InsideAresta to 1 so that it breaks the while looop
            IncideAresta = 1;
        }
        else
            //insert into the list the item that we had in our Graph
            TLista_Insere(&ListaAdj, TLista_Tamanho(&ListaAdj), Adj);
    }

    //keep looping while we empty our temporary list 
    while (TLista_Retira(&ListaAdj, TLista_Tamanho(&ListaAdj)-1, &Adj))
        //Insert into the graph adj[u] location the item "empty" that / that we already know
        TLista_Insere(&pGrafo->Adj[u], TLista_Tamanho(&pGrafo->Adj[u]), Adj);

    //return "true" aka 1 that all went well
    return IncideAresta;
}

TLista *TGrafo_ListaAdj(TGrafo *pGrafo, TVertice u)
{
    //create two lists
    TAdjacencia Adj;
    TLista *pLista;
    TLista ListaAdj;

    TLista_Inicia(&ListaAdj);
    //open space in memory for one of them
    pLista = (TLista *) malloc(sizeof(TLista));
    //inicialize pLista
    TLista_Inicia(pLista);
    
    //keep looping while you remove all of the itens from the Graph list on the respectively location [u] and save into Adj(has vertices and arestas)
    while(TLista_Retira(&pGrafo->Adj[u], TLista_Tamanho(&pGrafo->Adj[u]) - 1, &Adj))
        //insert the "info" of Adj temporary into the ListAdj 
        TLista_Insere(&ListaAdj, TLista_Tamanho(&pGrafo->Adj[u]), Adj);

    //keep looping while you remove all of the Adj info into the temporary ListaAdj
    while(TLista_Retira(&ListaAdj, TLista_Tamanho(&ListaAdj) - 1, &Adj))
    {
        //save the Adj info into both the Graph AGAIN and the pLista which we are going to return to the user
        TLista_Insere(&pGrafo->Adj[u], TLista_Tamanho(&pGrafo->Adj[u]), Adj);
        TLista_Insere(pLista, TLista_Tamanho(pLista), Adj);
    }
    return pLista;
}

int TGrafo_NVertices (TGrafo *pGrafo)
{
    return (pGrafo->NVertices);
}

int TGrafo_NArestas (TGrafo *pGrafo)
{
    return (pGrafo->NArestas);
}
