int NumeroElementos(No * L) { //retorna o numero de elementos de encadeada
	if(L==NULL){
		return 0;
	}
	else{
		int x=NumeroElementos(L->Prox);
		return x+1;
	}
}

int Maior(No * L) { //retorna o maximo de uma encadeada 
	if(L->Prox==NULL){
		return L->E;
	}
	else{
		int x=Maior(L->Prox);
		if(x<L->E){
			return L->E;
		}
		else{
			return x;
		}
	}
}

int Ultimo(No * L) { //retorna o ultimo elemento
	if(L==NULL){
		return -1;
	}
	else{
		if(L->Prox==NULL){
			return L->E;
		}
		else{
			return Ultimo(L->Prox);
		}
	}
}
