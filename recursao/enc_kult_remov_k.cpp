int KUltimo(No* L, int k, int &contador){
	if(L==NULL){
		return -1;
	}
	else{
		int x=KUltimo(L->Prox,k,contador);
		contador++;
		if(k==contador){ //achou!!
			return L->E;
		}
		return x; //porque ?
	}
}
int KUltimo(No * L, int k) {
	int contador=0;
	return KUltimo(L,k,contador);
}

void RemoveMaiores(No * &L, int k) {
	if(L!=NULL){
		RemoveMaiores(L->Prox,k);
		if(L->E>k){
			No* p=L->Prox;
			free(L);
			L=p;
		}
	}
}
