#include <stdio.h> 
#include <stdlib.h>
typedef struct No{
    int E;
    No* Prox;
}No;

typedef struct Pilha{
    No* Topo;
    int N;
}Pilha;

int Desempilha(Pilha &P) {
	No * n = P.Topo; int x = n->E;
	P.Topo = P.Topo->Prox;
	free(n);
	P.N--;
	return x;
}

void Empilha(Pilha &P, int x) {
	No * n = (No *) malloc(sizeof(No));
	n->E = x;
	n->Prox = P.Topo;
	P.Topo = n;
	P.N++;
}

void Constroi(Pilha &P) {
	P.Topo = NULL; P.N = 0;
}

int Topo(Pilha &P) {
	return P.Topo->E;
}
int main(void){
    Pilha menor,maior;
    Constroi(menor);Constroi(maior);
	int n;
	while (1) {
		scanf("%d", &n);
		if(n==0){
			break;
		}
		if(maior.N==0 || n>Topo(maior)){
			Empilha(maior,n);
		}
		else{
            Empilha(menor,n);
		}
    }
    while(menor.N>0){
        printf("%d\n",Desempilha(menor));
    }
    while(maior.N>0){
        Empilha(menor,Desempilha(maior));
    }
    while(menor.N>0){
        printf("%d\n",Desempilha(menor));
    }
    return 0;
}
