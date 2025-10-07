typedef struct No {
	int E;
	No * Prox;
} No;
void InsereEnc(No * &L, int e, No * &u) {  //funcoes auxiliares
	No * novo = (No *) malloc(sizeof(No));
	novo->E = e; novo->Prox = NULL; 
	if (u == NULL) {
		L = novo; 
	} else {
		u->Prox = novo;
	}
	u = novo; 
}

void Destroi(No * L) { //funcoes auxiliares 
	No * p, * pr; p = L; 
	while (p != NULL) {
		pr = p; p = p->Prox; 
		free(pr);
	}
}
void InsereInicioEnc(No * &L, int e) { //funcoes auxiliares 
	No * novo = (No *) malloc(sizeof(No));
	novo->E = e; novo->Prox = L; L = novo; 
}

long long int AvaliaPolinomio(No * P, int x) { //avalia o polinomio com x dado como param
	No* p=P;
	long long int saida=0;
	long long int potencia=(long long int) x/x;
	while (p!=NULL){
		saida+=(long long int) (p->E*potencia);
		potencia=(long long int) potencia*x;
		
		p=p->Prox;
	}
	return saida;
}



No * SomaPolinomios(No * P, No * Q) { //soma polinomios
	No* saida=NULL; No* ultimo1=NULL;
	No* copia=NULL;  No* ultimo2=NULL;
	No* p=P;   No* q=Q;
	int elemento;
	while (p!=NULL || q!=NULL){
		if (p==NULL){
			elemento=q->E;
			q=q->Prox;
		}
		else if(q==NULL){
			elemento=p->E;
			p=p->Prox;
		}
		else{
			elemento=q->E+p->E;
			p=p->Prox;
			q=q->Prox;
		}
		InsereEnc(copia,elemento,ultimo2);
		if (elemento!=0){
			No* copiador=copia;
			while(copiador!=NULL){
				InsereEnc(saida,copiador->E,ultimo1);
				copiador=copiador->Prox;
			}
			Destroi(copia);
			ultimo2=NULL;
			copia=NULL;
		}
	}
	if (saida==NULL){
		InsereEnc(saida,0,ultimo1);
	}
	Destroi(copia);
	return saida;
}

No * ProdutoPolinomioEscalar(No * P, int a) { //produto polinomio por escalar
	No* saida=NULL; No* ultimo1=NULL;
	No* p=P; No* copia=NULL;
	No* ultimo2=NULL;
	while (p!=NULL){
		int elemento=p->E*a;
		InsereEnc(copia,elemento,ultimo2);
		if (elemento!=0){
			No* iterador=copia;
			while (iterador!=NULL){
				InsereEnc(saida,iterador->E,ultimo1);
				iterador=iterador->Prox;
			}
			ultimo2=NULL;
			copia=NULL;
		}
		p=p->Prox;
	}
	Destroi(copia);
	if (saida==NULL){
		InsereEnc(saida,0,ultimo1);
	}
	return saida;
}
No * ProdutoPolinomios(No * P, No * Q) {
	No* p=P;
	int grau=0;
	No* saida=NULL;
	while(p!=NULL){
		int elemento=p->E;
		No* soma=ProdutoPolinomioEscalar(Q,elemento);
		for(int i=0;i<grau;i++){
			InsereInicioEnc(soma,0);
		}
		grau++;
		saida=SomaPolinomios(soma,saida);
		Destroi(soma);
		p=p->Prox;
	}
	return saida;
}
