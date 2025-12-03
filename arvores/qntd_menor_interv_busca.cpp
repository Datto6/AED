int QuantidadeMenorIgual(No * T, int a) {
	if(T==NULL){
		return 0;
	}
	else{
		if(T->E>a){
			return QuantidadeMenorIgual(T->Esq,a);
		}
		else{
			int q=1;
			if(T->Esq!=NULL){
				q+=T->Esq->Q;
			}
			return QuantidadeMenorIgual(T->Dir,a)+ q;
		}
	}
}

int QuantidadeIntervalo(No * T, int a, int b) {
	int menorb=QuantidadeMenorIgual(T,b);
	int menora=QuantidadeMenorIgual(T,a-1);
	return menorb-menora;
}
