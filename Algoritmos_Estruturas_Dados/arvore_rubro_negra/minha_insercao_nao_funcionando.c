
//Libraries
#include <stdio.h>
#include <stdlib.h>

// Tree pointer
typedef struct NO* ArvLLRB;

// Color type definition
#define RED 1
#define BLACK 0

#define DIR 1
#define ESQ 0

int lado, lado_ant = -1;


// Type struct of LLRB tree
struct NO {
    int info;
    struct NO *esq;
    struct NO *dir;
    struct NO *pai;
    int cor;
};

void printTree(ArvLLRB no, int ident);
//Create new Tree
ArvLLRB* cria_ArvLLRB()
{
    ArvLLRB* raiz = (ArvLLRB*) malloc(sizeof(ArvLLRB));
    if(raiz != NULL)
    {
        *raiz = NULL;
    }
    return raiz;
}


struct NO* createNode(int info,int cor)
{
    struct NO* myNode = (struct NO*) malloc(sizeof(struct NO));
    myNode -> esq = NULL;
    myNode -> dir = NULL;
    myNode -> info = info;
 
    // New Node which is created is
    // always red in color.
    myNode -> cor = RED;
    return myNode;
}


struct NO* rotacionaEsquerda(struct NO* myNode)
{
    struct NO*filho = myNode->dir;
    struct NO*filhoesq = filho->esq;

    filho->esq = myNode;
    myNode->dir = filhoesq;

    return filho;
}

struct NO* rotacionaDireita(struct NO* myNode)
{
    struct NO*filho = myNode->esq;
    struct NO*filhoDir = filho->dir;

    filho->dir = myNode;
    myNode->esq = filhoDir;

    return filho;
}


int isRed(struct NO* myNode)
{
    if (myNode == NULL)
       return 0;
    if(myNode->cor == RED)
        return  1;
    else
        return 0;
}

// utility function to swap color of two
// nodes.
void swapColors(struct NO* node1,struct NO* node2)
{
    int temp = node1 -> cor;
    node1 -> cor = node2 -> cor;
    node2 -> cor = temp;
}

// insertion into Left Leaning Red Black Tree.
struct NO* insert(struct NO* myNode, int info)
{
    // Normal insertion code for any Binary
    // Search tree.
    if (myNode == NULL)
        return createNode(info, BLACK);   
 
    if (info < myNode -> info)
    {
        myNode->esq = insert(myNode->esq, info);
        lado_ant = lado;
        lado = ESQ;

        //Caso 1
        if(isRed(myNode->esq) && isRed(myNode->dir))
        {
            if(myNode->esq->esq != NULL)
            {
                if(isRed(myNode->esq->esq))
                {
                    printf("Caso1_esq\n");
                    myNode->cor = !myNode->cor;
                    myNode->esq->cor = !myNode->esq->cor;
                    myNode->dir->cor = !myNode->dir->cor;
                }
            }
        }

        //Caso 3 pt.1 
        else if(isRed(myNode->esq) && !isRed(myNode->dir) && lado_ant == ESQ)
        {
            if(myNode->esq->esq != NULL)
            {
                if(isRed(myNode->esq->esq))
                {
                    printf("Caso3pt.1\n");
                    swapColors(myNode, myNode->esq);
                    myNode = rotacionaDireita(myNode);
                }
            }
        }

        //Caso 2 pt.1
        else if(isRed(myNode->esq) && !isRed(myNode->dir) && lado_ant == DIR)
        {
            if(myNode->esq->dir != NULL)
            {
                printf("Caso2pt.1 | myNode: %i\n", myNode->info);
                myNode->esq = rotacionaEsquerda(myNode->esq);
                swapColors(myNode, myNode->esq);
                myNode = rotacionaDireita(myNode);
            }
        }
    }
 
    else if (info > myNode -> info)
    {
        myNode->dir = insert(myNode->dir, info);
        lado_ant = lado;
        lado = DIR;

        //Caso 1
        if(isRed(myNode->esq) && isRed(myNode->dir))
        {
            if(myNode->dir->dir != NULL)
            {
                if(isRed(myNode->dir->dir))
                {
                    printf("Caso1_dir | myNode: %i\n", myNode->info);
                    myNode->cor = !myNode->cor;
                    myNode->esq->cor = !myNode->esq->cor;
                    myNode->dir->cor = !myNode->dir->cor;
                }
            }
        }

        //Caso 3 pt.2
        else if(isRed(myNode->dir) && !isRed(myNode->esq) && lado_ant == DIR)
        {
            if(myNode->dir->dir != NULL)
            {
                if(isRed(myNode->dir->dir))
                {
                    printf("Caso3pt.2 |myNode = %i\n", myNode->info);
                    swapColors(myNode, myNode->dir);
                    myNode = rotacionaEsquerda(myNode);
                }
            }
        }

        //Caso 2 pt.2
        else if(isRed(myNode->dir) && !isRed(myNode->esq) && lado_ant == ESQ)
        {
            if(myNode->dir->esq != NULL)
            {
                printf("Caso2pt.2| myNode: %i\n", myNode->info);
                myNode->dir = rotacionaDireita(myNode->dir);
                swapColors(myNode, myNode->dir);
                myNode = rotacionaEsquerda(myNode);
            }
        }
    }
    else   
        return myNode;

    return myNode;
}


// This function will only keep control of the insertion
int insere_ArvLLRB(ArvLLRB* raiz, int valor)
{
    // call other function to actually inserts the value
    *raiz = insert(*raiz, valor);

    // if everything works fine
    if((*raiz) != NULL)
    {
        // change the color of the root to black
        (*raiz)->cor = BLACK;
    }
    return 1;
}



void libera_NO(struct NO* no)
{
    // check if the node is already poiting to null
    if(no == NULL)
        return;
    // if not, call recursivily the left and right child of it
    libera_NO(no->esq);
    libera_NO(no->dir);
    // after all, free memory
    free(no);
    // set no poiting to null
    no = NULL;
}

void libera_ArvLLRB(ArvLLRB* raiz)
{
    // check if the root is already pointing to null
    if(raiz == NULL)
        return;
    // call the libera_NO function
    libera_NO(*raiz);
    // free memory
    free(raiz);
}

int consulta_ArvLLRB(ArvLLRB *raiz, int valor)
{
    // check if the root is pointing to null
    if(raiz == NULL)
        return 0;
    
    // create an temp node struct that points to root
    struct NO* atual = *raiz;

    // keep looping until atual found the bottom
    while(atual != NULL)
    {
        // check if the valor is equals the one that is on the info field of the tree
        if(valor == atual->info)
        {
            // if so, we found it, return 1
            return 1;
        }
        // check if the valor is greater then the value on the tree
        if(valor > atual->info)
        {
            // then go search into the right side of the tree
            atual = atual->dir;
        }
        // if it isn't greater, must be less
        else
        {
            // go search into the left side of the tree
            atual = atual->esq;
        }
    }
    // if we reach the bottom and didn't returned 1, then there's no valor on the tree, return 0
    return 0;
}

// Function to control the remotion function in the red-black tree
int remove_ArvLLRB(ArvLLRB *raiz, int valor)
{
    // check if there's the value in the tree
    if(consulta_ArvLLRB(raiz, valor))
    {
        // if so, create an node pointing at the root
        struct NO* h = *raiz;
        // check if the root is not pointing to null
        if(*raiz != NULL)
        {
            // then, set the color of the the root to be black
            (*raiz)->cor = BLACK;
        }
        // return 1 meaning the remotion works fine
        return 1;
    }
    // if there weren't the value there
    else
    {
        // return 0 meaning the remotion did not work
        return 0;
    }
}


int altura_ArvLLRB(ArvLLRB raiz)
{
    if (raiz == NULL)
        return 0;
    int alt_esq = altura_ArvLLRB(raiz->esq);
    int alt_dir = altura_ArvLLRB(raiz->dir);
    if (alt_esq > alt_dir)
        return (alt_esq + 1);
    else
        return(alt_dir + 1);
}

int altura_black_ArvLLRB(ArvLLRB raiz)
{
    int black_height = 0;

    while(raiz != NULL)
    {
        if(raiz->cor == BLACK)
        {
            black_height++;
        }
        raiz = raiz->dir;
    }
    return black_height;
}

ArvLLRB ponteiro_busca_no(ArvLLRB *raiz, int valor)
{
    if(raiz == NULL)
        return 0;

    struct NO* atual = *raiz;

    while(atual != NULL)
    {
        //check if the valor to be found is equal the slot info into the atual node
        if(valor == atual->info)
        {
            // if it is equal, we found, return 1
            return atual;
        }
        // if not found, check if is greater than the inf into the atual node
        if(valor > atual->info)
            // if is greater, then the value to be found is on the right of the binary tree, so go there
            atual = atual->dir;
        else
            //else, aka if the value to be found is less than the one into node->info, it's in the left of the tree, go there
            atual = atual->esq;
    }
    return 0;
}
// Simple function to print the tree in order to understand what's going on
void printTree(ArvLLRB no, int ident)
{
    int i;

    if(no != NULL)
    {
        printf("|");

        for(i = 0; i < ident-1; i++)
            printf("-");
        if(no->cor == BLACK)
            printf("(%d[P])\n", no->info);
        if(no->cor == RED)
            printf("(%d[V])\n", no->info);
        printTree(no->esq, ident+2);
        printTree(no->dir, ident+2);
    }
}
