bool Busca(int **B, int n, int x) {
//procura do tipo escada, matriz ordenada em coluna e linha.
	int j=n-1;
	int i=0;
	while((i<n) && (j>=0)){
		if (B[i][j]<x){ //desce uma linha, colunas em forma crescente 
			i++;
		}
		else if (B[i][j]>x){ //desce uma coluna, cada linha disposta de forma crescente tb
			j--;
		}
		else{
			return true;
		}
	}
	return false;
}

void InsertionSort(int B[], int elementos){
	if (elementos>0){
		InsertionSort(B,elementos-1);
		int i=elementos;
		while ((i>1) && (B[i]<B[i-1])){
			int tmp;
			B[i]=tmp;
			B[i]=B[i-1];
			B[i-1]=tmp;
			--i;
		}
	}
}

void InsereListaOrdenada(int L[], int &N, int x) {
    // insere x na lista ordenada L
    int i = 0;
	while ((i < N) && (L[i] < x)) {
		i = i+1;
	}
	for (int j = N-1; j >= i; j--) {
		L[j+1] = L[j];
	}
	L[i] = x;
	N = N+1;
}
int QuantosContidos(int LS[], int N, No * LE) { 
//dado LS de N elementos, LE de N^2 elementos, checar quantos de LS estao em LE com complexidade O(N^2 logN)
	int LSord[N];
	int contador=0;
	for (int i=1;i<N;i++){
		LSord[i]=LS[i];
	}
	InsertionSort(LSord,N);
	No * p=LE;
	while (p!=NULL){
		if (buscaBinaria(LS,N,p->E)){
			contador++;
		}
		p=p->Prox;
	}
	return contador;
}


//forma alternativa

int QuantosContidos(int LS[], int N, No * LE) {
	int * LSO = (int *) malloc(sizeof(int)*N); int NO = 0;
	for (int i=0; i<N; i++) {
		InsereListaOrdenada(LSO, NO, LS[i]);
	}
	int Q = 0; 
	No * p = LE;
	while (p != NULL) {
		if (BuscaListaOrdenada(LSO, NO, p->E)) {
			Q = Q+1;
		}
		p = p->Prox;
	}
	free(LSO);
	return Q;
}
