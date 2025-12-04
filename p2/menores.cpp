#include <stdio.h> 
#include <stdlib.h>

typedef struct No {
	int E;
	No * Esq;
	No * Dir;
} No;
int min(int x, int y){
    if (x>y){
        return y;
    }
    return x;
}

bool Menores(No* T,int &minimo){
    if(T==NULL){
        minimo=INT_MAX; return true;
    }
    else{
        int me,md;
        bool dir=Menores(T->Dir,md);
        bool esq=Menores(T->Esq,me);
        bool local= (T->E<=me) && (T->E<=md);
        minimo=min(min(me,md),T->E);
        return local && dir && esq;
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
    //           -10
    //         /    \
    //       1       20
    //     /  \     /  \
    //    3    2   15   11
    //

    No* raiz = novoNo(-10);
    raiz->Esq = novoNo(1);
    raiz->Dir = novoNo(20);

    raiz->Esq->Esq = novoNo(3);
    raiz->Esq->Dir = novoNo(2);

    raiz->Dir->Esq = novoNo(25);
    raiz->Dir->Dir = novoNo(34);

    // Testando
    int minimo;
    printf("%d",Menores(raiz,minimo));

    return 0;
}
