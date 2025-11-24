No * Soma2a2(No * L) {
	/* insert your code here */
	if(L==NULL || L->Prox==NULL){
		return NULL;
	}
	else{
		No* novo=(No*) malloc(sizeof(No));
		novo=Soma2a2(L->Prox);
		No* saida=NULL; No* ultimo=NULL;
		No* p=L->Prox;
		while(p!=NULL){
			InsereFinal(saida,p->E+L->E,ultimo);
			p=p->Prox;
		}
		p=novo;
		while(p!=NULL){
			InsereFinal(saida,p->E,ultimo);
			p=p->Prox;
		}
		return saida;
	}
}
