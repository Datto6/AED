No* Inverte(No* L, No* &ult){
	if(L==NULL){
		return NULL;
	}
	else{
		No* novo=Inverte(L->Prox,ult);
		InsereFinal(novo,L->E,ult);
		return novo;
	}
}	
No * Inverte(No * L) {
	No* saida=L; No* ultimo=NULL;
	return Inverte(saida,ultimo);
}

void PreencheNumeroCaminhos(int n, int i, int j, bool ** Obs, long long int ** S) {
	if (S[i][j] != -1) {
		return; //valor já foi previamente computado 
	} else if (Obs[i][j]) {
		S[i][j] = 0;
	} else if ((i==n-1) && (j==n-1)) {
		S[i][j] = 1;
	} else {
		S[i][j] = 0;
		if (j < n-1) {	
			PreencheNumeroCaminhos(n, i, j+1, Obs, S);
			S[i][j] = S[i][j] + S[i][j+1];
		} 
		if (i < n-1) {
			PreencheNumeroCaminhos(n, i+1, j, Obs, S);
			S[i][j] = S[i][j] + S[i+1][j];
		}
	}	
}

long long int NumeroCaminhos(int n, int m, int X[], int Y[]) {
	//bool Obs[n][n];
	bool ** Obs = (bool **) malloc(sizeof(bool *)*n);
	//long long int Obs[n][n];
	long long int ** S = (long long int **) malloc(sizeof(long long int *)*n);
	for (int i=0; i<n; i++) {
		Obs[i] = (bool *) malloc(sizeof(bool)*n);
		S[i] = (long long int *) malloc(sizeof(long long int)*n);
		for (int j=0; j<n; j++) {
			Obs[i][j] = false;
			S[i][j] = -1; //indica que o valor não foi ainda computado
		}
	}
	for (int i=0; i<m; i++) {
		Obs[X[i]-1][Y[i]-1] = true; //X[i],Y[i] são valores entre 1 e n
	}

	PreencheNumeroCaminhos(n, 0, 0, Obs, S);
	long long int r = S[0][0];
	for (int i=0; i<n; i++) {
		free(S[i]); free(Obs[i]);
	}
	free(S); free(Obs);
	return r;
}
