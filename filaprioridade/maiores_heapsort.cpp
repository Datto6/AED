void Maiores(int L[], int n, int k, int M[]) { //k maiores elementos de L, usando fila de prioridade
	FilaPrioridade F; Constroi(F, k+1);
	for (int i=0; i<n; i++) {
		Enfileira(F, -L[i]);
		if (Tamanho(F) == k+1) {
			Desenfileira(F);
		}
	}
	for (int i=0; i<k; i++) {
		M[i] = -Desenfileira(F);
	}
	Destroi(F);
}

void Ordenar(int L[], int n) {
	// esse método de ordenação é chamado de HeapSort
	/* insert your code here */
	FilaPrioridade F;
	Constroi(F,n);
	for(int i=0;i<n;i++){
		Enfileira(F,L[i]);
	}
	for(int i=n-1;i>=0;i--){
		L[i]=Desenfileira(F);
	}
}
