typedef struct No { //so para explicitar o tipo do no usado
	int E;
	No * Prox;
} No;

int NumeroElementos(No * L) { //numero de elementos de lista encadeada
	No* p=L;
	int contador=0;
	while (p!=NULL){
		contador++;
		p=p->Prox;
	}
	return contador;
}

int Maior(No * L) { //maior elemento de lista
	No* p=L;
	int max=p->E;
	while (p!=NULL){
		if (p->E>max){
			max=p->E;
		}
		p=p->Prox;
	}
	return max;
}

int Ultimo(No * L) { //ultimo elemento da lista, lista encadeada circular, -1 se nao tiver elementos
	No* p=L;
	if (p==NULL){
		return -1;
	}
	int ultimo;
	int volta=0;
	while ((p!=L) || (!volta)){
		ultimo=p->E;
		if (p==L->Prox){
			volta=1;
		}
		p=p->Prox;
	}
	return ultimo;
}
