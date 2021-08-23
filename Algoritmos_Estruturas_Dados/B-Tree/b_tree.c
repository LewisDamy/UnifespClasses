#include <stdio.h>
#include <stdlib.h>

#define MAX 4
#define MIN 2

struct My_BTree {
  int valor[MAX + 1], count;  
  struct My_BTree *pagina[MAX + 1];
};

struct My_BTree *raiz;

// Create node
struct My_BTree *Cria_no(int valor, struct My_BTree *filho) 
{
    // create new node of struct My_BTree
    struct My_BTree *Novo_No;
    // allocate new space for the new node of struct My_BTree
    Novo_No = (struct My_BTree *)malloc(sizeof(struct My_BTree));
    // save the value of the array 1
    Novo_No->valor[1] = valor;
    // add one to the counter 1 in the page
    Novo_No->count = 1;
    // point the page 0 to the root
    Novo_No->pagina[0] = raiz;
    // point the page 1 to the child
    Novo_No->pagina[1] = filho;
    //retorn the new node created 
    return Novo_No;
}

//Functions
void Imprime_BTree(struct My_BTree *myno);
void Insere_no(int valor, int prox, struct My_BTree *no, struct My_BTree *filho);
void Divide_no(int valor, int *pvalor, int prox, struct My_BTree *no, struct My_BTree *filho, struct My_BTree **Novo_No);
int Define_valor(int valor, int *pvalor, struct My_BTree *no, struct My_BTree **filho);
void Pesquisa_valor(int valor, int *prox, struct My_BTree *myno);

// Define valor 
int Define_valor(int valor, int *pvalor, struct My_BTree *no, struct My_BTree **filho) 
{
    //define int
    int prox;

    // check if the node is not empty
    if (!no) 
    {
        // save the value into the value
        *pvalor = valor;
        // point the sun at null
        *filho = NULL;
        return 1;
    }
    // check if the value is less the the value on the list
    if (valor < no->valor[1]) 
    {
        // if so, save it into prox
        prox = 0;
    }
    else 
        {
        // interate though the list of the values 
        for (prox = no->count;
            (valor < no->valor[prox] && prox > 1); prox--)
          ;
        // check if the value is equals to one in the list of values
        if (valor == no->valor[prox]) 
        {
            // if so, we cannot insert, return 0
            return 0;
        }
    }
    // check if the value is define by calling the function
    if (Define_valor(valor, pvalor, no->pagina[prox], filho)) 
    {
        // is the value is greater than the max limit amount of space
        if (no->count < MAX) 
        {
            // if so, then we can insert 
            Insere_no(*pvalor, prox, no, *filho);
        } 
        else 
        {
            // else, we can split the new element list
            Divide_no(*pvalor, pvalor, prox, no, *filho, filho);
            return 1;
        }
    }
    return 0;
}

// insere no
void Insere_no(int valor, int prox, struct My_BTree *no, struct My_BTree *filho) 
{
    // define j como sendo o valor do contador do no
    int j = no->count;
    // loop enquanto o valor do j nao for igual ao prox
    while (j > prox) 
    {
        // Define o valor do no sendo 1 a menos
        no->valor[j + 1] = no->valor[j];
        // define o valor da pagina sendo 1 a menos
        no->pagina[j + 1] = no->pagina[j];
        // diminui por 1 o j
        j--;
    }
    // quando achamos o valor do no
    // salva o valor e o filho na arvore
    no->valor[j + 1] = valor;
    no->pagina[j + 1] = filho;
    // adiciona 1 no coutador do no
    no->count++;
}


// insere valor 
void insert(int valor) 
{
    // Define 2 variables
    int flag, i;
    // create new node type My_BTree called child
    struct My_BTree *filho;
    // Call the function Define_valor and save it in the flag variable
    flag = Define_valor(valor, &i, raiz, &filho);
    // check if the flag was created, create new node 
    if (flag)
        raiz = Cria_no(i, filho);
}

// Divide no
void Divide_no(int valor, int *pvalor, int prox, struct My_BTree *no, struct My_BTree *filho, struct My_BTree **Novo_No) 
{
    // define 
    int media, j;

    // check if there's an minimum space to use
    if (prox > MIN)
        media = MIN + 1;
    // if so, save it 
    else
        media = MIN;

    // create new space 
    *Novo_No = (struct My_BTree *)malloc(sizeof(struct My_BTree));

    // save the value in j
    j = media + 1;

    // keep interating while we reach the location value of the list to be insert
    while (j <= MAX) 
    {
        (*Novo_No)->valor[j - media] = no->valor[j];
        (*Novo_No)->pagina[j - media] = no->pagina[j];
        j++;
    }

    no->count = media;
    (*Novo_No)->count = MAX - media;

    if (prox <= MIN) 
    {
        // insert the node in the prox
        Insere_no(valor, prox, no, filho);
    } 
    else 
    {
        // insert the value in the prox - media location
        Insere_no(valor, prox - media, *Novo_No, filho);
    }
    *pvalor = no->valor[no->count];
    (*Novo_No)->pagina[0] = no->pagina[no->count];
    no->count--;
}

// value to check if the num was found on the Pesquisa_valor function 
int found = 0;

// Pesquisa valor no no
void Pesquisa_valor(int valor, int *prox, struct My_BTree *myno) 
{
  if (!myno) 
  {
    return;
  }

  if (valor < myno->valor[1]) 
  {
    *prox = 0;
  } 
  else 
  {
    for (*prox = myno->count; 
        (valor < myno->valor[*prox] && *prox > 1); (*prox)--)
      ;
    if (valor == myno->valor[*prox]) 
    {
      printf("%d", myno->count);
      found = 1;
      return;
    }
  }
  Pesquisa_valor(valor, prox, myno->pagina[*prox]);

  return;
}

// function to print tree 
void Imprime_BTree(struct My_BTree *myno) 
{
  int i;
  if (myno) 
  {
    for (i = 0; i < myno->count; i++) 
    {
      Imprime_BTree(myno->pagina[i]);
      printf("%d ", myno->valor[i + 1]);
    }
    Imprime_BTree(myno->pagina[i]);
  }