#include <stdio.h>
#include <stdlib.h>


typedef struct NO* ArvBin;

//struct of the Node
struct NO{
    int info;
    //pointer to esq and dir
    struct NO *esq;
    struct NO *dir;
};


ArvBin* cria_ArvBin()
{
    //creating a pointer called root
    ArvBin* raiz = (ArvBin*) malloc(sizeof(ArvBin));

    // if everything went good
    if(raiz != NULL)
        //set the content of the root to point to null
        *raiz = NULL;

    return raiz;
} 


void libera_NO(struct NO* no)
{
    // Check if node is null
    if(no == NULL)
        // if so, nothing we can do about it
        return;
    
    // ATTENTION: This method is by recursive function
                    // aka the node will only be removed if the same is pointing to NULL 
                    // this means that the function will go through the last node of the left
                    // and then remove that node and keep going back until it reach an node that still has the right side aka an sibling
                    // and then will do the same to the right side of the tree

    // run recursivily the left side of the node
    libera_NO(no->esq);
    // run recursivily the right side of the node
    libera_NO(no->dir);
    // free the space allocated for the node
    free(no);
    // set that node to point to null aka nothing
    no = NULL;
}


void libera_ArvBin(ArvBin* raiz)
{
    //check if we free root
    if(raiz == NULL)
        // if root is null, nothing we can do about it
        return;

    // call the function libera_NO which will free each node of the tree
    libera_NO(*raiz);
    // free space of the that we alocate the root pointer
    free(raiz);
}


int insere_ArvBin(ArvBin* raiz, int valor)
{
    // if the root is equal to null
    if(raiz == NULL)
        // there was a problem in the creation of the tree, aka, something went wrong
        return 0;

    // Allocate new space into memory for new node by using malloc
    struct NO* novo;
    novo = (struct NO*) malloc(sizeof(struct NO));

    // If something went wrong in allocation of the memory
    if(novo == NULL)
        //cannot do the insertion
        return 0;

    // save the value to be insert
    novo->info = valor;
    // knowing that the new node will be a "folha" aka last element of the tree, set dir and esq to NULL
    novo->dir = NULL;
    novo->esq = NULL;

    //SEARCHING FOR THE PLACE TO INSERT:

    //if Tree is empty
    if(*raiz == NULL)
        // cool, just insert where root is pointing at, aka change null of root to "novo"
        *raiz = novo;

    // aka, if Tree is not empty
    else
    {
        //create two pointers, one is pointing at the first element of tree, and the other to null
        struct NO* atual = *raiz;
        struct NO* ant = NULL;
        //keep looping while the pointer atual finds an null place aka the bottom of the tree
        while(atual != NULL)
        {
            // save what atual is pointing which is an element of the tree to the ant
            ant = atual;
            //check if the value that we want to insert is equals to the one that ant is pointing at
            if(valor == atual->info)
            {
                //though away novo, because we don't want to insert the same element twice in our tree
                free(novo);
                //kill the function, 'cause they are trying to insert an element that already exists
                return 0;
            }

            //if the value that we want to insert is greater than what atual is pointing at
            if(valor > atual->info)
                //"send" atual to the right side of the tree aka to search for insertion in the right node ...
                atual = atual->dir;
            else
                // if the value that we want to insert is less than what atual is pointing at
                // "send" atual to the left side of the tree aka to search for insertion in the left node ...
                atual = atual->esq;
        }
        //once you reach an "folha" aka an node that points to null, the pointer "atual" is pointing NULL!
        // and "ant" is pointing to what "atual" were pointing before point to NULL which is an node that is in the bottom of the tree
        
        // check if the value is grater than what ant is pointing at
        if(valor > ant->info)
            //Insert that novo node to be an child in the right side of that "folha" which will not be anymore "folha" because it got an child
            ant->dir = novo;
        // if the value is less thant what ant is pointing at
        else
            //Insert that novo node to be an child in the left side of that "folha" 
            ant->esq = novo;
    }
    // everything went good
    return 1;
}

//Function responsable to treat the 3 types of removal of nodes
struct NO* remove_atual(struct NO* atual) 
{
    //creating two node structs temporary
    struct NO *no1, *no2;

    //check if the atual->esq (the node to be removed) is equal to null
    //AKA if is the First type THE TYPE THAT HAS A NODE WITH NO CHILD AND THE NODE WITH ONLY ONE CHILD
    if(atual->esq == NULL)
    {
        // if so, set the new node (that implicit points both esq and dir to null 'cause are new)
        // atual->dir could be pointing at null if is the "NO CHILD CASE" or pointing at one child, so set it equal to whatever
        no2 = atual->dir;
        //free space memory of atual (the one that we want to remove)
        free(atual);
        //return the node no2 that we just replaced
        return no2;
    }

    //searching for child most to the right into the left subtree
    if(atual->dir == NULL)
    {
        // if so, set the new node (that implicit points both esq and dir to null 'cause are new)
        // atual->dir could be pointing at null if is the "NO CHILD CASE" or pointing at one child, so set it equal to whatever
        no2 = atual->esq;
        //free space memory of atual (the one that we want to remove)
        free(atual);
        //return the node no2 that we just replaced
        return no2;
    }

    no1 = atual;
    no2 = atual->dir;
    //keep doing until the no2 is null, aka, finds the most bottom right child
    while(no2->esq != NULL)
    {
        no1 = no2;
        no2 = no2->esq;
    }
    // no2 is the node before the r in the order e-r-d
    // no1 is the father of node no2

    //copying most right child from left subtree to be moved where we want to remove the atual node
    if(no1 != atual)
    {
        no1->esq = no2->dir;
        no2->dir = atual->dir;
    }
    //set the new no2 to be where toe atual were before removed and free memory of atual node
    no2->esq = atual->esq;
    free(atual);
    return no2;
}


// Function responsable to search the node to be removed
int remove_ArvBin(ArvBin *raiz, int valor)
{
    //check if the tree is valid
    if(raiz == NULL)
        return 0;
    
    //create 2 type Node that one receive null and the other the root pointer
    struct NO* ant = NULL;
    struct NO* atual = *raiz;

    //keep looping while atual does not equal null
    while(atual != NULL)
    {
        //This part is to find the node to be removed and treated by calling the secondary function 
        //Check if the content of the node is the same of the atual->info aka check if the content of the node is the same as to be removed
        if(valor == atual->info)
        {
            //check now, if the content of the root, if is the same so we are removing the root
            if(atual == *raiz)
                // root receive the content of the function remove_atual
                *raiz = remove_atual(atual);
            //else aka, if the content is not the same as the root, then it must be in one node
            else
            {
                //check if the content of the right child is equal to atual
                if(ant->dir == atual)
                    // if so call the remove_atual function to remove the right next' child node
                    // because NOTE: the ant is POINTING AT atual, we want to remove the atual
                    // and the new ant->dir will receive the new node or null depends on the remove_atual function
                    ant->dir = remove_atual(atual);
                else
                    // if then "ant->dir == atual" then must be the "ant->esq == atual" so call the function to remove it
                    ant->esq = remove_atual(atual);
            }
            return 1;
        }
        // This part keep looking the tree to find the node to be removed 

        // move the ant to "keep looking" by being the new atual
        ant = atual;

        // check if the valor to be remove is greater of the info in atual node
        if(valor > atual->info)
            // if so, then the node to be removed is in the right side of the tree, go search there
            atual = atual->dir;

        else
            // if it's not greater, aka, the valor to be removed is greater of the info in atual node
            // then the node to be removed is in the left side of the tree, go search there
            atual = atual->esq;
    }
    return 0;
}



int estaVazia_ArvBin(ArvBin *raiz)
{
    // if the root is equal to null
    if(raiz == NULL)
        // there was a problem in the creation of the tree, aka, something went wrong
        return 1;
    // if the content of the root if equal to null
    if(*raiz == NULL)
        //there's no node that the root is point at, aka, there is no insertion of node in that root, it's empty
        return 1;
    // aka, else, the tree is not empty
    return 0;
}

// Function to count how many nodes there is in my tree
int totalNO_ArvBin(ArvBin *raiz)
{
    //check if tree were created correctly
    if (raiz == NULL)
        //if the root is null, aka, there were a problem in the creation of the tree
        // aka the high of the tree is zero
        return 0;
    //check if root points to null
    if (*raiz == NULL)
        // if so, there is no node aka the high of the tree is zero
        return 0;

    //ATENTION: Recursion situation 

    // The first call of the function will be the first node because is where the root is pointing at
    // Secondly, it will visit the left child if it exists and keep going until there is a left side of the child that is pointing at null it will return 1
    // When it reaches the last left node that is pointing at null, it will go back, but looking to the right children if found it will return 1
    // Now we have the both bottom nodes have one, then that father of those children will receive the alt_esq + alt_dir + 1(if itself) and return 3
    // And this will keep going until it reaches the first node that will sum the child alt_esq = x and alt_dir = y 
    // and the totalNO will be x+y+1 

    //Keep calling the function by passing the address with "&" of the left side node
    int alt_esq = totalNO_ArvBin(&((*raiz)->esq));
    //Keep calling the function by passing the address with "&" of the right side node
    int alt_dir = totalNO_ArvBin(&((*raiz)->dir));

    //
    return(alt_esq + alt_dir + 1);
}


int altura_ArvBin(ArvBin *raiz)
{
    //check if tree were created correctly
    if (raiz == NULL)
        //if the root is null, aka, there were a problem in the creation of the tree
        // aka the high of the tree is zero
        return 0;
    //check if root points to null
    if (*raiz == NULL)
        // if so, there is no node aka the high of the tree is zero
        return 0;
    
    //ATENTION: Recursion situation 
    
    // The first call of the function will be the first node because is where the root is pointing at
    // Secondly, it will visit the left child if it exists and keep going until there is a left side of the child that is pointing at null it will return 0
    // When it reaches the last left node that is pointing at null, it will go back, but looking to the right children if found it will return 1
    // Now we have the both bottom have size one, then that father of those children will receive high of 1 + 1 = 2, 
    // And it will keeps going and comparing and adding one until the first node is reach, then it will compare which of this children will have most high and add 1

    //Keep calling the function by passing the address with "&" of the left side node
    int alt_esq = altura_ArvBin(&((*raiz)->esq));
    //Keep calling the function by passing the address with "&" of the right side node
    int alt_dir = altura_ArvBin(&((*raiz)->dir));

    //check which of the sides of the tree is bigger, left or right
    if (alt_esq > alt_dir)
        // if the left side is bigger, than add 1 and return the integer
        return (alt_esq + 1);
    else
        // if the right side is bigger, than add 1 and return the integer
        return(alt_dir + 1);
}


// return 1 if found and 0 if not found
int consulta_ArvBin(ArvBin *raiz, int valor)
{
    //check if the tree exists
    if(raiz == NULL)
        return 0;
    
    //create type node that points to what root is pointing which is the tree
    struct NO* atual = *raiz;
    
    //while the content of atual does not reach null, keep looping
    while(atual != NULL)
    {
        //check if the valor to be found is equal the slot info into the atual node
        if(valor == atual->info)
        {
            // if it is equal, we found, return 1
            return 1;
        }
        // if not found, check if is greater than the inf into the atual node
        if(valor > atual->info)
            // if is greater, then the value to be found is on the right of the binary tree, so go there
            atual = atual->dir;
        else
            //else, aka if the value to be found is less than the one into node->info, it's in the left of the tree, go there
            atual = atual->esq;
    }
    // after searching until reach null, aka, reach node with no child the bottom of the tree, there are no value, return 0
    return 0;
}

ArvBin ponteiro_busca_no(ArvBin *raiz, int valor)
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


void printTree(ArvBin no, int ident)
{
    int i;

    if(no != NULL)
    {
        printf("|");

        for(i = 0; i < ident-1; i++)
            printf("-");
        printf("(%d)\n", no->info);
        printTree(no->esq, ident+2);
        printTree(no->dir, ident+2);
    }
}




// Walks to the left child, then root, then right child
void emOrdem_ArvBin(ArvBin *raiz)
{
    //check if tree were created correctly
    if(raiz == NULL)
        //if the root is null, aka, there were a problem in the creation of the tree
        return;

    //check if root points to null
    if(*raiz != NULL)
    {
        //Recursion function: Drawing in notebook
        emOrdem_ArvBin(&((*raiz)->esq));
        printf("%d ",(*raiz)->info);
        emOrdem_ArvBin(&((*raiz)->dir));
    }
}

// Walks to the root, then left child then right child
void preOrdem_ArvBin(ArvBin *raiz)
{
    //check if tree were created correctly
    if(raiz == NULL)
        //if the root is null, aka, there were a problem in the creation of the tree
        return;
    
    //check if root points to null
    if(*raiz != NULL)
    {

        //Recursion function: Drawing in notebook
        printf("%d ",(*raiz)->info);
        preOrdem_ArvBin(&((*raiz)->esq));
        preOrdem_ArvBin(&((*raiz)->dir));
    }
}
