#include <stdio.h>
#include <stdlib.h>
#define VERMELHO 0
#define PRETO 1
//defini��o da estrutura de um n� da �rvore rubro negra
typedef struct no{
	int chave, cor;
	struct no *esq, *dir, *pai;
}no;

//fun��es para manipula��o da �rvore
no* inicia_ARN(){
    return NULL;
}

//fun��o para liberar a mem�ria alocada pelos n�s da �rvore
void libera_ARN(no *raiz){
    if(raiz!=NULL){
        libera_ARN(raiz->esq);
        libera_ARN(raiz->dir);
        free(raiz);
    }
}

//fun��o que aloca um n� de cor vermelha para ser inserido na �rvore
no* cria_no_vermelho(int chave_insercao, no *pai){
    no* novo=(no*) malloc(sizeof(no));
    novo->pai=pai;
    novo->esq=NULL;
    novo->dir=NULL;
    novo->cor=VERMELHO;
    novo->chave=chave_insercao;
    return novo;
}

//fun��o que aloca um n� de cor preta para ser inserido na �rvore
no* cria_no_preto(int chave_insercao){
    no* novo=(no*) malloc(sizeof(no));
    novo->pai=NULL;
    novo->esq=NULL;
    novo->dir=NULL;
    novo->cor=PRETO;
    novo->chave=chave_insercao;
    return novo;
}

//fun��o para checar se um n� � o filho da esquerda de seu pai.
//retorna verdadeiro(!=0) se for, retorna falso(0) se n�o for
int eh_filho_da_esquerda(no* raiz){
    no* pai=raiz->pai;
    return pai->esq==raiz;
}

//fun��o que retorna o irm�o de um n� na arvore
no* encontra_irmao_no(no* raiz){
    no* pai=raiz->pai;
    if(eh_filho_da_esquerda(raiz)){
        return pai->dir;
    }
    return pai->esq;
}

//fun��o para realizar uma rota��o para a direita com o piv� em um n� raiz
//o inteiro muda_cor serve como indicador, se h� necessidade de trocar as cores dos n�s
void rotaciona_dir(no* raiz, int muda_cor){
    no* pai=raiz->pai;
    raiz->pai=pai->pai;//atualizamos o pai do n� a ser rotacionado
    if(pai->pai!=NULL){//caso o n� rotacionado tenha um av�
        //encadeamos o n� a ser rotacionado na �rvore.
        if(pai->pai->dir==pai){
            pai->pai->dir=raiz;
        }
		else{
            pai->pai->esq=raiz;
		}
    }
    //realizando a rota��o
    no* direita=raiz->dir;
	raiz->dir=pai;
	pai->pai=raiz;
    pai->esq=direita;
    if(direita!=NULL){
        direita->pai=pai;
    }
    //checando se precisamos mudar as cores dos n�s
    if(muda_cor){
        raiz->cor=PRETO;
		pai->cor=VERMELHO;
    }
}

//fun��o para realizar uma rota��o para a esquerda, com piv� em um n� raiz recebido.
//o inteiro muda_cor serve como indicador, se h� necessidade de trocar as cores dos n�s
void rotaciona_esq(no* raiz, int muda_cor){
    no* pai=raiz->pai;
    raiz->pai=pai->pai;//atualizando o pai do n� piv� a ser rotacionado
    if(pai->pai!=NULL){//caso o n� rotacionado tenha um av�
        //encadeamos o n� piv� a ser rotacionado na �rvore, seu pai agora ser� seu av�
        if(pai->pai->dir==pai){
            pai->pai->dir=raiz;
        }
		else{
            pai->pai->esq=raiz;
		}
    }
    //realizando a rota��o
    no* esquerda=raiz->esq;
    raiz->esq=pai;
    pai->pai=raiz;
    pai->dir=esquerda;
    if(esquerda!=NULL){
        esquerda->pai=pai;
    }
    //checando se h� necessidade de mudar as cores dos n�s
    if(muda_cor){
        raiz->cor=PRETO;
        pai->cor=VERMELHO;
    }
}

//fun��o para inserir um n� dentro da arvore rubro negra
//recebe a raiz da �rvore, a chave do n� a ser inserido e o pai desse n� e aloca o novo n�  na �rvore
no* insere_ARN(no* pai, no* raiz, int chave_insercao){
    if(raiz==NULL){//caso estejamos em uma folha ou a arvore est� vazia
        if(pai!=NULL){//caso estejamos em uma folha os novos n�s inseridos s�o vermelhos
            return cria_no_vermelho(chave_insercao, pai);
        }
        return cria_no_preto(chave_insercao);//caso a arvore esteja vazia, a raiz deve ser preta
    }
    //variavel auxiliar para indicar onde o novo n� foi inserido, ser� utilizado para auxiliar nas opera��es de balanceamento
    //se estiver na esquerda, 1, se estiver na direita 0
    int estaNaEsquerda;
    if(raiz->chave>chave_insercao){//chave do n� a ser inserido � menor que a chave do n� atual, prosseguimos para a esquerda
        no* esquerda=insere_ARN(raiz, raiz->esq, chave_insercao);
        //alocando o n� na arvore
        if(esquerda==raiz->pai){
            return esquerda;
        }
        raiz->esq=esquerda;
        //atualizando a variavel auxiliar.
        estaNaEsquerda=1;
    }
	else if(raiz->chave<chave_insercao){//chave do n� a ser inserido � maior que a chave do n� atual, prosseguimos para a direita
        no* direita=insere_ARN(raiz, raiz->dir, chave_insercao);
        //alocando o no na arvore
        if(direita==raiz->pai){
            return direita;
        }
		raiz->dir=direita;
		//atualizando a variavel auxiliar.
        estaNaEsquerda=0;
    }

    //realizando balanceamento e a recolora��o dos n�s caso seja necess�rio.
    if(estaNaEsquerda){//inser��o na esquerda
        if(raiz->cor==VERMELHO && raiz->esq->cor==VERMELHO){//dois n�s vermelhos seguidos na esquerda, viola��o da propriedade
            no* irmao=encontra_irmao_no(raiz);//encontrando o tio
            if(!irmao || irmao->cor==PRETO){//caso o tio seja de cor preta
                if(eh_filho_da_esquerda(raiz)){//n�s s�o filhos da esquerda, rotacionamos a direita e mudamos a cor
                    rotaciona_dir(raiz, 1);
                }
				else{//n�s s�o filhos da direita, rota��o dupla RL
                    rotaciona_dir(raiz->esq, 0);
                    raiz=raiz->pai;
                    rotaciona_esq(raiz, 1);
                }
            }
			else{//tio de cor vermelha, trocamos a cor dos n�s
                raiz->cor=PRETO;
				irmao->cor=PRETO;
                if(raiz->pai->pai!=NULL){
                    raiz->pai->cor=VERMELHO;
                }
            }
        }
    }
	else{//inser��o na direita
        if(raiz->cor==VERMELHO && raiz->dir->cor==VERMELHO){//dois n�s vermelhos seguidos na direita, viola��o das propriedades
            no* irmao=encontra_irmao_no(raiz);//encontrando o tio
            if(!irmao || irmao->cor==PRETO){//tio de cor preta
                if(!eh_filho_da_esquerda(raiz)){//n�s est�o a direita, rotacionamos a esquerda e mudamos de cor
                    rotaciona_esq(raiz, 1);
                }
				else{//n�s est�o a esquerda, rota��o dupla LR
                    rotaciona_esq(raiz->dir, 0);
					raiz=raiz->pai;
					rotaciona_dir(raiz, 1);
                }
            }
			else{//tio de cor vermelha, trocamos a cor dos n�s
                raiz->cor=PRETO;
                irmao->cor=PRETO;
                if(raiz->pai->pai!=NULL){
                    raiz->pai->cor=VERMELHO;
                }
            }
        }
    }
    //caso n�o haja viola��o das propriedades, retorna o n� inalterado
    return raiz;
}

//fun��o de pesquisa dentro da �rvore
//recebe a raiz da arvore e o valor a ser procurado, retorna o endere�o do n� que tem o valor buscado
no* pesquisa_ARN(no *raiz, int chave_pesquisa){
    //caso encontremos o no procurado ou atingimos uma folha
    if(raiz==NULL || raiz->chave==chave_pesquisa){
        return raiz;
    }
    if(chave_pesquisa<raiz->chave){//chave proccurada menor que a chave da raiz, o la�o desejado deve estar na subarvore da esquerda
        return pesquisa_ARN(raiz->esq, chave_pesquisa);
    }
    else{//chave proccurada maior que a chave da raiz, o la�o desejado deve estar na subarvore da esquerda
        return pesquisa_ARN(raiz->dir, chave_pesquisa);
    }
}

//fun��o que retorna a altura de um n�
//recebe o n� e compara recursivamente a profundidade de cada uma das suas sub�rvores, retorna o maior valor
//em caso de �rvore vazia, retorna -1
int altura_ARN(no *raiz){
    if(raiz!=NULL){
        int altura_esq=altura_ARN(raiz->esq);
        int altura_dir=altura_ARN(raiz->dir);
        if(altura_esq>altura_dir){
            return altura_esq+1;
        }
        else{
            return altura_dir+1;
        }
    }
    return -1;
}

//fun��o que retorna a altura negra de um n�, que � a quantidade de n�s de cor preta de um n� at� uma de suas folhas
//como a altura negra � a mesma independente do caminho que tomamos na arvore, portanto escolhemos um caminho e contamos a quantidade
//de n�s negros
int altura_negra_ARN(no *raiz){
    int altura_negra=0;
    while(raiz!=NULL){
        if(raiz->cor==PRETO){
            altura_negra++;
        }
        raiz=raiz->dir;
    }
    return altura_negra;
}

//fun��o para imprimir a �rvore em pre-ordem
void imprime_ARN(no* raiz){
	if(raiz!=NULL){
        printf("%d ", raiz->chave);
        imprime_ARN(raiz->esq);
        imprime_ARN(raiz->dir);
    }
}
