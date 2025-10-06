typedef struct No {
	int E;
	No * Ant;
	No * Prox;
} No;


int KUltimo(No * L, int k) { //kultimo de lista encadeada circular com no cabeca , complexidade 0[n]
	No * p=L->Prox;
	No * q=L->Prox;
	int volta=0;
	int contador=0;
	int elemento;
	for (int i=0;i<k;i++){
		if (p==L){
			return -1;
		}
		p=p->Prox;
	}
	while (p!=L){
		p=p->Prox;
		q=q->Prox;
		
	}
	return q->E;
	
}
int KUltimo(No * L, int k) { //k-ultimo elemento, complexidade O[k]
	//lista duplamente encadeada circular
	No * p=L;
	if (L==NULL){
		return -1;
	}
	if (k==0){
		return -1;
	}
	int tamanho=0;
	for (int i=0;i<k;i++){
		p=p->Ant;
		if (p==L && i!=0){ //i!=0 se for so um elemento
			if (i!=k-1){ // i==k-1 seria a ultima iteracao, leva em conta k== tamanho da lista.
				return -1; 
			}
		}
	}
	return p->E;
}
