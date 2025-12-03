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
