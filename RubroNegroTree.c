#include <stdio.h>
#include <stdlib.h>

typedef enum {
    red, //red=0
    black //black=1
}Cor;

typedef struct RBnode{
    int dado;
    Cor cor;
    struct RBnode *esquerda;
    struct RBnode *direita;
    struct RBnode *parente;
}RBnode;


RBnode *nil; //sentinela; (folha preta)

void inicializar(){
    nil = malloc(sizeof(RBnode));
    if(nil==NULL){
        printf("erro ao alocar");
        return;
    }else{
        nil->cor = black;
        nil->direita = nil->esquerda = nil->parente = nil;
    }
}


RBnode *criaNo(int dado){
    RBnode *node = (RBnode*)malloc(sizeof(RBnode));
    if(node==NULL){
        printf("erro ao alocar");
        return NULL;
    }else{
        node->dado = dado;
        node->cor = red;
        node->direita=node->esquerda=node->parente=nil;
    }
    return node;
}


void leftRotate(RBnode **root, RBnode *x){
    RBnode *y = x->direita;
    x->direita = y->esquerda;
    if(y->esquerda !=nil){
        y->esquerda->parente = x;
    }    
    y->parente = x->parente;
    if(x->parente==nil){ //eh raiz
        *root = y; //mudo o y vira raiz
    }else if(x == x->parente->esquerda){
        x->parente->esquerda = y;
    }else{
        x->parente->direita = y;
    }
    y->esquerda = x;
    x->parente = y;
}

void rightRotate(RBnode **root, RBnode *y){
    RBnode *x = y->esquerda;
    y->esquerda = x->direita;
    if(x->direita !=nil){
        x->direita->parente=y;
    }
    x->parente = y->parente;
    if(y->parente==nil){
        *root = x; //é raiz
    }else if(y==y->parente->esquerda){
        y->parente->esquerda = x;
    }else{
        y->parente->direita = x;
    }
    x->direita = y;
    y->parente = x;
}


void insertRules(RBnode **root, RBnode *z){
    while(z->parente->cor== red){ //enquanto pai for vermelho
        if(z->parente == z->parente->parente->esquerda){
            RBnode *y = z->parente->parente->direita; //esse é o meu tio
            if(y->cor==red){ //se tio eh vermelho
                z->parente->cor = black;
                y->cor = black;
                z->parente->parente->cor = red;
                z=z->parente->parente; //depois de resolver tudo eu vou passar a apontar o lugar do avo e dai o codigo ainda roda se o bisavo for vermelho ele roda ate arrumar tudo
            }else{ //se o tio nao eh vermelho
                if(z==z->parente->direita){ //se eu for o filho do lado direito
                    z = z->parente;
                    leftRotate(root,z);
                }
                z->parente->cor=black;
                z->parente->parente->cor = red;
                rightRotate(root,z->parente->parente);
            }

        }else{  //se meu pai nao for o filho da esquerda
            RBnode * y = z->parente->parente->esquerda;
            if(y->cor==red){
                z->parente->cor = black;
                y->cor = black;
                z->parente->parente->cor=red;
                z=z->parente->parente;
            }else{
                if(z==z->parente->esquerda){
                    z=z->parente;
                    rightRotate(root,z);
                }
                z->parente->cor = black;
                z->parente->parente->cor=red;
                leftRotate(root,z->parente->parente);
            }
        }
    }
    (*root)->cor = black; //raiz sempre preta;
}


void inserirElementos(RBnode **root,int dado){
    RBnode * z = criaNo(dado);
    RBnode *y = nil, *x =*root;
    while(x!=nil){
        y=x;
        if(z->dado < x->dado){
            x=x->esquerda;
        }else{
            x=x->direita;
        }
    }
    z->parente = y;
    if(y==nil){
        *root = z;
    }else if(z->dado < y->dado){
        y->esquerda=z;
    }else{
        y->direita=z;
    }
    z->direita=z->esquerda=nil;
    insertRules(root,z);
}

int main(){

}

