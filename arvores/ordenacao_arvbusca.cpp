void Insere(No * &T, int x) {
	if(T!=NULL){
		if(T->E<x){
			return Insere(T->Dir,x);
		}
		else if(T->E>x){
			return Insere(T->Esq,x);
		}

	}
	else{
		T=(No*) malloc(sizeof(No));
		T->E=x;
		T->Dir=NULL;
		T->Esq=NULL;
	}
}
void percorretudo(No* T, int A[],int &i){
	if(T!=NULL){
		percorretudo(T->Esq,A,i);
		A[i]=T->E;
		i++;
		percorretudo(T->Dir,A,i);
	}
}
void Ordenar(int A[], int N) {
	No* T=NULL;
	for(int i=0;i<N;i++){
		Insere(T,A[i]);
	}
	int i=0;
	percorretudo(T,A,i);
}
