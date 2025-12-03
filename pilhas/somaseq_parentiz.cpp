int SomaSequenciaOperacoes(int S[], int n) {
	Pilha aux;
	Constroi(aux);
	for(int i=0;i<n;i++){
		if(S[i]!=0){
			Empilha(aux,S[i]);
		}
		else{
			if(aux.N>0){
				Desempilha(aux);
			}

		}
	}
	int tam=aux.N;
	int soma=0;
	for (int i=0;i<tam;i++){
		soma+=Desempilha(aux);
	}
	return soma;
}

bool VerificaParentizacao(Parentese E[], int n) {
	Pilha P;
	Constroi(P);
	for(int i=0;i<n;i++){
		if(E[i].desc=='('){
			Empilha(P,E[i].tipo); //so adicionando, nao tem problema 
		}
		else {
			if(Tamanho(P)<=0 || Desempilha(P)!=E[i].tipo){ //ve se ta fechando o tipo certo, se nao, ja capota
				Destroi(P);
				return false;
			}
		}
	}
	if(Tamanho(P)==0){
		Destroi(P);
		return true;
	}
	return false;
}
