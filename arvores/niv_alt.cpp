void AtuNivAux(No* T, int h){
	if(T!=NULL){
		AtuNivAux(T->Esq,h+1);
		AtuNivAux(T->Dir,h+1);
		T->niv=h;
	}
}
void AtualizaNivel(No * T) {
	AtuNivAux(T,1);
}

void AtualizaAltura(No * T) {
	if (T!=NULL){
		AtualizaAltura(T->Esq);
		AtualizaAltura(T->Dir);
		int he=0;int hd=0;
		if(T->Esq!=NULL){
			he=T->Esq->h;
		}
		if(T->Dir!=NULL){
			hd=T->Dir->h;
		}
		T->h=max(hd,he)+1;
	}
}
