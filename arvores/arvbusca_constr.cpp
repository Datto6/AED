bool EhArvoreAux(No* T, int &min, int &max){
	if (T==NULL){
		min=INT_MAX;
		max=-INT_MAX;
		return true;
	}
	else {
		int md,Md,me,Me;
		bool ehbuscaesq=EhArvoreAux(T->Esq,me,Me);
		bool ehbuscadir=EhArvoreAux(T->Dir,md,Md);
		min=minimo(T->E,minimo(md,me));
		max=maximo(maximo(Me,Md),T->E);
		return  ehbuscadir  && ehbuscaesq && (md>T->E) && (Me<T->E);
	}

}
bool EhArvoreBusca(No * T) {
	int min,Max;
	return EhArvoreAux(T, min, Max);
}

No * CriarArvoreAlturaMinima(int x[], int ini, int fim) {
	if(ini>fim){
		return NULL;
	}
	int meio=(ini+fim)/2;
	No* raiz=(No*) malloc(sizeof(No));
	raiz->E=x[meio];
	raiz->Esq=CriarArvoreAlturaMinima(x,ini,meio-1);
	raiz->Dir=CriarArvoreAlturaMinima(x,meio+1,fim);
	return raiz;
}
