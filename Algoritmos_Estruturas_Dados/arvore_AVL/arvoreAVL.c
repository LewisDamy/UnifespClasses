#include <stdio.h>
#include <stdlib.h>

typedef struct NO* ArvAVL;

struct NO{
    int info;
    int alt;
    struct NO *esq;
    struct NO *dir;
};

ArvAVL* cria_ArvAVL()
{
    // creating a pointer called root
    ArvAVL* raiz = (ArvAVL*) malloc(sizeof(ArvAVL));

    // if everything went good
    if (raiz != NULL)
    {
        // set the content of the root to point to null
        *raiz = NULL;
    }
    return raiz;
}

void libera_NO(struct NO* no)
{
    // check if node is null
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
    // free the space allocated fr the node
    free(no);
    // set that node to point to null aka nothing
    no = NULL;
}

void libera_ArvAVL(ArvAVL* raiz)
{
    // check if we free root
    if(raiz == NULL)
        // if root is null, nothing we can do about it
        return;
    
    // call the function libera_NO which will free node of the tree
    libera_NO(*raiz);
    // free space that we alocate to root pointer
    free(raiz);
}

int altura_NO(struct NO* no)
{
    // check if the node doesn't exist
    if(no == NULL)
        // if so, return -1 meaning that it does not exists
        return -1;
    
    else // if there is an node
        // return the value that is in alt
        return no->alt;
}

int fatorBalanceamento_NO(struct NO* no)
{
    // calculate the difference between the hight from node of the left
    // and right, and return the module value that's what labs func means
    return labs(altura_NO(no->esq) - altura_NO(no->dir));
}

/*
    ATTENTION: the value - or + is only important in order to rotate
    if we the value of balancement is positive means that you've insert
    on the left side, however if the fatorBalanceamento is negative, then
    you've insert on the right side.
*/

int maior(int x, int y)
{
    if(x > y)
        return x;
    else
        return y;
}

//========================ROTACOES================================

void RotacaoLL(ArvAVL *pA)
{
    // create an pointer
    struct NO *pB;
    // set the new pointer to point at whatever the pA-dir is pointing aka the left child
    pB = (*pA)->esq;
    // the A node will take the right child of B, to become the left child of A
    (*pA)->esq = pB->dir;
    // Set the right child from B to become the node A
    pB->dir = *pA;
    // Calculate the new hight from A
    (*pA)->alt = maior(altura_NO((*pA)->esq), altura_NO((*pA)->dir)) + 1;
    // Calculate the new hight from B
    pB->alt = maior(altura_NO(pB->dir),(*pA)->alt) + 1;
    // set both pointers to be on the new father B node
    (*pA) = pB;
}

void RotacaoRR(ArvAVL *pA)
{
    // create an pointer 
    struct NO *pB;
    //set the new pointer to point at what the pA->dir is pointing aka the right son 
    pB = (*pA)->dir;
    // set the dir from the pA to point at what pB->esq is pointing aka the A will take the left child of B
    (*pA)->dir = pB->esq;
    // set the B->esq to point at the node A
    pB->esq = (*pA);
    // Calculate the new hight from A 
    (*pA)->alt = maior(altura_NO((*pA)->esq), altura_NO((*pA)->dir)) + 1;
    // Calculate the new hight form B
    pB->alt = maior(altura_NO(pB->dir), (*pA)->alt) + 1;
    // set both pointers to be on the new father A node
    (*pA) = pB;
}

void RotacaoLR(ArvAVL *pA)
{
    // Right - Right Rotation
    RotacaoRR(&(*pA)->esq);
    // Left - Left Rotation  
    RotacaoLL(pA);
}

void RotacaoRL(ArvAVL *pA)
{
    // Left - Left Rotation
    RotacaoLL(&(*pA)->dir);
    // Right - Right Rotation
    RotacaoRR(pA);
}

int insere_ArvAVL(ArvAVL *raiz, int valor)
{
    int res;
    //1st case: Empty tree or leaf node
    if(*raiz == NULL)
    {
        // create new pointer node
        struct NO *novo;
        // allocate the size necessary for the new node
        novo = (struct NO*)malloc(sizeof(struct NO));

        // Check if the node was created right
        if(novo == NULL)
            return 0;

        // If so, then set the value to be stored in info
        novo->info = valor;
        // Set the hight to be 0
        novo->alt = 0;
        // point the left pointer to null
        novo->esq = NULL;
        // point the right pointer to null
        novo->dir = NULL;
        // point the new node to be the real tree
        *raiz = novo;
        return 1;
    }
    // Set the atual node to point to the root of the three
    struct NO *atual = *raiz;
    // Check if the value to be insert is less than what's the info' root 
    if(valor < atual->info)
    {
        // If so then, you need to insert into the left side of the tree, calling recursivily
        // if you successifully insert on the left side, aka == 1
        if((res = insere_ArvAVL(&(atual->esq), valor)) == 1)
        {
            // check the math to see if there's need to make the rotation, aka the balance is greater or equals to 2
            if(fatorBalanceamento_NO(atual) >= 2)
            {
                // the value that has been inserted is less than the info from the left node
                if(valor < (*raiz)->esq->info )
                {
                    // then we need to rotate LL
                    RotacaoLL(raiz);
                }
                else
                {
                    // else, we need to rotate LR
                    RotacaoLR(raiz);
                }
            }
        }
    }
    else // Check if the value to be insert is greater than what's the info' root
    {
        if(valor > atual->info)
        {
            // if so then, call recursively to insert into the right side of the tree
            if((res = insere_ArvAVL(&(atual->dir), valor)) == 1)
            {
                // check if the balancement factor is not higher than or equals to 2
                if(fatorBalanceamento_NO(atual) >= 2)
                {
                    // If so, we need to rotate
                    // but first check if it's an RR rotation, aka, if the right' node info is greater than value
                    if((*raiz)->dir->info < valor)
                    {
                        // If that's the case, make an RR rotation
                        RotacaoRR(raiz);
                    }
                    else
                    {
                        // else, that's the need to make the RL rotation
                        RotacaoRL(raiz);
                    }
                }
            }
        }
        else
        {
            // Something went workg and it must be that the value to be added is duplicated
            printf("Valor duplicado!!\n");
            return 0;
        }
    }
    // raise the value of the hight of the tree by one, by calling maior function to see
    // which side of the tree is greater 
    atual->alt = maior(altura_NO(atual->esq),altura_NO(atual->dir)) + 1;

    return res;
}

// Function to search for smallerst value
struct NO* procuraMenor(struct NO* atual)
{
    //create new node1 and set to be pointing at what'ever you want to search
    struct NO *no1 = atual;
    // create another new node2 and set to be pointing at whatever it's on the left of the atual (to be search node)
    struct NO *no2 = atual->esq;
    // Keep iterating until the node2 reaches the last node->esq which is NULL
    while(no2 != NULL)
    {
        
        // set the node1 to be pointing at the node1
        no1 = no2;
        // move the node2 to be pointing at wahtever it's on the esq from the node
        no2 = no2->esq;
    }
    // Remember that once we found the null, the node1 will be pointing at the last element
    // and then we found the smallest element and return it
    return no1;
}

int remove_ArvAVL(ArvAVL *raiz, int valor)
{
    // Check if the value exists
	if(*raiz == NULL)
    {
        // if not, print this
	    printf("valor nao existe!!\n");
        // return 0 means something went wrong
	    return 0;
	}

    int res;

    // Check if the value to be removed in less then the value from the root
	if(valor < (*raiz)->info)
    {
        // if so, then we need to search by recursion and then removed on the left side of the tree
	    if((res = remove_ArvAVL(&(*raiz)->esq,valor)) == 1)
        {
            // once we found it by interation, remove it and then check if need to rotate
            if(fatorBalanceamento_NO(*raiz) >= 2)
            {
                // check the hight from the right left node and the right right node 
                if(altura_NO((*raiz)->dir->esq) <= altura_NO((*raiz)->dir->dir))
                {
                    // if the right right is greater or equals to, then we need to do RR
                    RotacaoRR(raiz);
                }
                else
                {
                    // Else, if the right left is grater, we need to do RL
                    RotacaoRL(raiz);
                }
            }
	    }
	}
    // Check if the value to be removed in greater then the value from the root
	if((*raiz)->info < valor)
    {
        // If so, then remove the element by recursion on the right sidfe of the tree
	    if((res = remove_ArvAVL(&(*raiz)->dir, valor)) == 1)
        {
            // check if we need to rotate
            if(fatorBalanceamento_NO(*raiz) >= 2)
            {
                // compare the hights 
                if(altura_NO((*raiz)->esq->dir) <= altura_NO((*raiz)->esq->esq))
                    RotacaoLL(raiz); 
                else
                    RotacaoLR(raiz);
            }
	    }
	}

    // Case if the node has 1 child or none
	if((*raiz)->info == valor)
    {
        // Check if the left or right child is none
	    if(((*raiz)->esq == NULL || (*raiz)->dir == NULL))
        {
            // create new node poiting at the root
			struct NO *oldNode = (*raiz);

			if((*raiz)->esq != NULL)
                *raiz = (*raiz)->esq;
            else
                *raiz = (*raiz)->dir;
            // free node 
			free(oldNode);
		}
        else // if the node has 2 child
        {
            // create new node but point it do the right left smallest node
			struct NO* temp = procuraMenor((*raiz)->dir);
            // copy the info from that node
			(*raiz)->info = temp->info;
            // remove the node
			remove_ArvAVL(&(*raiz)->dir, (*raiz)->info);
            // check if there's need to balance 
            if(fatorBalanceamento_NO(*raiz) >= 2)
            {
                // if so, then compare the rights 
				if(altura_NO((*raiz)->esq->dir) <= altura_NO((*raiz)->esq->esq))
					RotacaoLL(raiz);
				else
					RotacaoLR(raiz);
			}
		}
        // check if the root still has something 
		if (*raiz != NULL)
            (*raiz)->alt = maior(altura_NO((*raiz)->esq),altura_NO((*raiz)->dir)) + 1;
		return 1;
	}
    // calculate new hight
	(*raiz)->alt = maior(altura_NO((*raiz)->esq),altura_NO((*raiz)->dir)) + 1;

	return res;
}

// Simple function to print the tree in order to understand what's going on
void printTree(ArvAVL no, int ident)
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

// return 1 if found and 0 if not found
int consulta_ArvAVL(ArvAVL *raiz, int valor)
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
        {
            // if is greater, then the value to be found is on the right of the binary tree, so go there
            atual = atual->dir;
        }
        else
        {
            //else, aka if the value to be found is less than the one into node->info, it's in the left of the tree, go there
            atual = atual->esq;
        }
    }
    // after searching until reach null, aka, reach node with no child the bottom of the tree, there are no value, return 0
    return 0;
}

ArvAVL ponteiro_busca_no(ArvAVL *raiz, int valor)
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