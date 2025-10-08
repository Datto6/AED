int * Concatenar(int L1[], int n1, int L2[], int n2) { //concatena duas listas lineares sequencias 
	int* nova= (int *) malloc(sizeof(int)*(n1+n2));
	for (int i=0;i<n1;i++){
		nova[i]=L1[i];
	}
	for (int i=0;i<n2;i++){
		nova[n1+i]=L2[i];
	}
	return nova;
}

No * Concatenar(No * L1, No * L2) { //concatena duas listas encadeadas
	/* insert your code here */
	struct No* p=L1;
	No* L=NULL;
	No* u=NULL;
	No* retorno=NULL;
	while (p!=NULL){
		Inserefim(L,p->E,u);
		p=p->Prox;
	}
	p=L2;
	while (p!=NULL){
		Inserefim(L,p->E,u);
		p=p->Prox;
	}
	return L;
}
