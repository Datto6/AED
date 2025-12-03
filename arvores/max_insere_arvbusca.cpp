int Maior(No * T) { //maior elemento numa arvore de busca
	if(T->Dir!=NULL){
		return Maior(T->Dir);
	}
	return T->E;
}

void Insere(No * &T, int x) { //insere numa arvore de busca, adiciona ao Q se ja tiver la
	if(T!=NULL){
		if(T->E==x){
			T->Q++;
			return;
		}
		else if(T->E<x){
			return Insere(T->Dir,x);
		}
		else if(T->E>x){
			return Insere(T->Esq,x);
		}

	}
	else{
		T=(No*) malloc(sizeof(No));
		T->E=x;
		T->Q=1;
		T->Dir=NULL;
		T->Esq=NULL;
	}
}
