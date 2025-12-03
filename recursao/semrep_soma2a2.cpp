No * SemRepeticoes(No * L) {
	if(L==NULL){
		return NULL;
	}
	else{
		No* novo=(No*) malloc(sizeof(No));
		novo=SemRepeticoes(L->Prox);
		No* p=novo;
		bool insira=true;
		while(p!=NULL){
			if(p->E==L->E){
				insira=false;
				break;
			}
			p=p->Prox;
		}
		if(insira){
			No* retorno= (No*) malloc(sizeof(No));
			retorno->E=L->E;
			retorno->Prox=novo;
			return retorno;
		}
		else{
			return novo;
		}
	}
}

No * Soma2a2(No * L) { // os dois dao no mesmo, mas menos mallocs no que ta sem comentario
	if(L==NULL || L->Prox==NULL){
		return NULL;
	}else {
		No * p; 
		No * R = Soma2a2(L->Prox);
		p = L->Prox;
		while (p != NULL) {
			Insere(R, L->E + p->E);
			p = p->Prox;
		}
		return R;
	}
	// }
	// else{
	// 	No* novo=Soma2a2(L->Prox);
	// 	No* saida=NULL; No* ultimo=NULL;
	// 	No* p=L->Prox;
	// 	while(p!=NULL){
	// 		InsereFinal(saida,p->E+L->E,ultimo);
	// 		p=p->Prox;
	// 	}
	// 	p=novo;
	// 	while(p!=NULL){
	// 		InsereFinal(saida,p->E,ultimo);
	// 		p=p->Prox;
	// 	}
	// 	return saida;
	// }
}
