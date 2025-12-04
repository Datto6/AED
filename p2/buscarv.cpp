#include <stdio.h> 
#include <stdlib.h>

typedef struct No {
	int E;
	No * Esq;
	No * Dir;
} No;

No * BuscaArv(No* T, int x){
    if(T==NULL){
        return NULL;
    }
    else{
        if(T->E==x){
            return T;
        }
        No* dir=BuscaArv(T->Dir,x);
        No* esq=BuscaArv(T->Esq,x);
        if(dir!=NULL){
            return dir;
        }
        else{
            return esq;
        }
    }
}
No* novoNo(int x){
    No* n = (No*)malloc(sizeof(No));
    n->E = x;
    n->Esq = NULL;
    n->Dir = NULL;
    return n;
}
int main() {

    // Construindo uma árvore manualmente:
    //
    //           10
    //         /    \
    //       5       20
    //     /  \     /  \
    //    3    7   15   30
    //

    No* raiz = novoNo(-10);
    raiz->Esq = novoNo(5);
    raiz->Dir = novoNo(20);

    raiz->Esq->Esq = novoNo(3);
    raiz->Esq->Dir = novoNo(7);

    raiz->Dir->Esq = novoNo(15);
    raiz->Dir->Dir = novoNo(30);

    // Testando
    int valoresTeste[] = {7, 15, 99, 3, 30, 10};
    int n = sizeof(valoresTeste)/sizeof(valoresTeste[0]);

    for(int i = 0; i < n; i++){
        int x = valoresTeste[i];
        No* resp = BuscaArv(raiz, x);

        if(resp != NULL)
            printf("Valor %d encontrado! Endereco = %p\n", x, (void*)resp);
        else
            printf("Valor %d NAO encontrado.\n", x);
    }

    return 0;
}
