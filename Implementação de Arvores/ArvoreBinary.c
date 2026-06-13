#include <stdio.h>
#include <stdlib.h>

//arvore binaria

typedef struct noArvore{
int dado;
struct noArvore *direita;
struct noArvore *esquerda;
}noArvore;


noArvore *criaNo(int valor){
    noArvore  *ptr = (noArvore*)malloc(sizeof(noArvore));
    if(ptr==NULL){
        printf("erro ao aloca");
        return NULL;
    }else{
        ptr->dado = valor;
        ptr->esquerda=NULL;
        ptr->direita=NULL;
        return ptr;
    }   
}
 

noArvore *inserir(noArvore *raiz,int valor){
    if(raiz==NULL){
        return criaNo(valor);
    }
    if(valor<raiz->dado){
        raiz->esquerda = inserir(raiz->esquerda,valor);
    }else{
        raiz->direita = inserir(raiz->direita,valor);
    }
    return raiz;
}
    

void imprimir(noArvore *raiz){  //  imprimir() inOrdem
    if(raiz!=NULL){
        imprimir(raiz->esquerda);
        printf("%d ",raiz->dado);
        imprimir(raiz->direita);
    }
}   


void imprimirPreOrdem(noArvore *raiz){
    if(raiz!=NULL){
        printf("%d ",raiz->dado);
        imprimirPreOrdem(raiz->esquerda);
        imprimirPreOrdem(raiz->direita);
    }
}

void imprimirPosOrdem(noArvore *raiz){
    if(raiz!=NULL){
        imprimirPosOrdem(raiz->esquerda);
        imprimirPosOrdem(raiz->direita);
        printf("%d ",raiz->dado);
    }
}

void menu(){
    int op,valor;
    noArvore *raiz=NULL;
    do{
        printf("0-SAIR || 1-INSERIR || 2-IMPRIMIR IN-ORDER || 3-IMPRIMIR PRE-ORDER || 4-IMPRIMIR POS-ORDEM");
        scanf("%d",&op);
        switch(op){
            case 0:
                printf("adeus...");
                break;
            case 1:
                printf("digite um valor: ");
                scanf("%d",&valor);
                raiz = inserir(raiz,valor);
                break;
            case 2:
                imprimir(raiz);
                break;
            case 3: 
                imprimirPreOrdem(raiz);
                break;
            case 4:
                imprimirPosOrdem(raiz);
                break;
            default:
                printf("digite algo certo");
                break;
        }
    }while(op!=0);
}                                                                                                                                                           


int main(){
    menu();
    return 0;
}