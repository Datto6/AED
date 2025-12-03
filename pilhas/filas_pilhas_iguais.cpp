bool FilasIdenticas(Fila &f1, Fila &f2) {
	Fila aux1; Fila aux2;
	Constroi(aux1); Constroi(aux2);
	bool retorno=true;
	if (f1.N!=f2.N){
		return false;
	}
	int iteracoes=f1.N;
	for(int i=0;i<iteracoes;i++){
		int x=Desenfileira(f1);
		int y=Desenfileira(f2);
		Enfileira(aux1,x);
		Enfileira(aux2,y);
		if (x!=y){
			retorno=false;
		}
	}
	for(int i=0;i<aux1.N;i++){
		Enfileira(f1,Desenfileira(aux1));
		Enfileira(f2,Desenfileira(aux2));
	}
	return retorno;
}

bool PilhasIdenticas(Pilha &p1, Pilha &p2) {
	Pilha aux1;	Pilha aux2;
	Constroi(aux1); Constroi(aux2);
	bool retorno=true;
	if (p1.N!=p2.N){
		return false;
	}
	int iteracoes=p1.N;
	for(int i=0;i<iteracoes;i++){
		int x=Desempilha(p1);
		int y=Desempilha(p2);
		Empilha(aux1,x);
		Empilha(aux2,y);
		if (x!=y){
			retorno=false;
		}
	}
	for(int i=0;i<aux1.N;i++){
		Empilha(p1,Desempilha(aux1));
		Empilha(p2,Desempilha(aux2));
	}
	return retorno;
}
