void AlternarPosNeg(int num[], int n) {
	/* num[0..n-1] são os números entrados pelo usuário */
	/* insert your code here */
	Fila negativos;
	Fila positivos;
	Constroi(negativos);
	Constroi(positivos);
	for (int i=0;i<n;i++){
		if(num[i]<0){
			Enfileira(negativos,num[i]);
		}
		else{
			Enfileira(positivos,num[i]);
		}
	}
	for(int i=0;i<n;i++){
		if(i%2==0){
			printf("%d ",Desenfileira(positivos));
		}
		else{
			printf("%d ",Desenfileira(negativos));
		}
	}
	printf("\n");
}

void Ordena(Pilha &P) {
	Pilha Q; Constroi(Q);
	int tamanho=P.N;
	for(int i=tamanho;i>0;i--){
		int min=Topo(P);
		for (int j=0;j<i;j++){
			int elem=Desempilha(P);
			Empilha(Q,elem);
			if(elem<min){
				min=elem;
			}
		}
		for (int j=0;j<i;j++){
			int elem=Desempilha(Q);
			if (elem!=min){
				Empilha(P,elem);
			}
		}
		Empilha(Q,min);
	}
	int tamfinal=Q.N;
	for(int i=0;i<tamfinal;i++){
		Empilha(P,Desempilha(Q));
	}
}

void Ordena(Pilha &P) {
	Pilha Q; Constroi(Q);
	int tamanho=P.N;
	while(P.N>0){
		int x=Desempilha(P);
		int contador=0;
		while(Q.N>0 && Topo(Q)>x){
			Empilha(P,Desempilha(Q));
			contador++;
		}
		Empilha(Q,x);
		for(int i=0;i<contador;i++){
			Empilha(Q,Desempilha(P));
		}
	}
	for(int i=0;i<tamanho;i++){
		Empilha(P,Desempilha(Q));
	}
}
