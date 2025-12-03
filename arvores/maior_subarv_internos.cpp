int MaiorSubarvore(No* T, int &soma){ //retorna maior subarvore
	if(T==NULL){
		soma=0;
		return 0;
	}
	else{
		int se,sd;
		int x=MaiorSubarvore(T->Esq,se);
		int y=MaiorSubarvore(T->Dir,sd);
		soma=se+sd+T->E;
		int total=soma;
		if(T->Esq!=NULL){
			total=max(total,x);
		}
		if(T->Dir!=NULL){
			total=max(total,y);
		}
		return total;
	}
}
int MaiorSubarvore(No * T) {
	int soma;
	return MaiorSubarvore(T,soma);
}

void ListaNosInternosAux(NoL* &L, No* T){ //retorna lista encadeada com nos internos
	if(T==NULL){
		return;
	}
	else{
		ListaNosInternosAux(L,T->Esq);
		ListaNosInternosAux(L,T->Dir);
    	if (T->Esq != NULL || T->Dir != NULL){
        	InsereInicio(L, T->E);
		}
	}
}
NoL * ListaNosInternos(No * T) {
	NoL* L=NULL;
	ListaNosInternosAux(L,T);
	return L;
}
