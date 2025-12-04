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
No* novoNo(int x){
    No* n = (No*)malloc(sizeof(No));
    n->E = x;
    n->Esq = NULL;
    n->Dir = NULL;
    return n;
}

No* Dobra(No* T){
    if(T!=NULL){
        No* saida=novoNo(T->E*2);
        saida->Dir=Dobra(T->Dir);
        saida->Esq=Dobra(T->Esq);
        return saida;
    }
    else{
        return NULL;
    }

}
void ExibeArvore(No* T, int nivel) {
    if (T == NULL) {
        for(int i = 0; i < nivel; i++) printf("   ");
        printf("·\n");
        return;
    }

    for(int i = 0; i < nivel; i++) printf("   ");
    printf("%d\n", T->E);

    ExibeArvore(T->Esq, nivel + 1);
    ExibeArvore(T->Dir, nivel + 1);
}

int main() {

    // Construindo uma árvore manualmente:
    //
    //           -10
    //         /    \
    //       1       20
    //     /  \     /  \
    //    3    2   25   34
    //

    No* raiz = novoNo(-10);
    raiz->Esq = novoNo(1);
    raiz->Dir = novoNo(20);

    raiz->Esq->Esq = novoNo(3);
    raiz->Esq->Dir = novoNo(2);

    raiz->Dir->Esq = novoNo(25);
    raiz->Dir->Dir = novoNo(34);

    // Testando
    No* nova=Dobra(raiz);
    ExibeArvore(raiz,0);
    ExibeArvore(nova,0);
    return 0;
}
