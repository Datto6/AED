int Maior(int A[], int n) { //maximo de vetor
	int max=A[0];
	for(int i=0;i<n;i++){
		if (A[i]>max){
			max=A[i];
		}
	}
	return max;
}

void ConcatenaPrefixos(char A[], char B[], int n, int m, char C[]) { //concatena prefixos de A e B em C
	for (int i=0;i<n;i++){
		C[i]=A[i];
	}
	for (int i=n;i<n+m;i++){
		C[i]=B[i-n];
	}
}

void PermutacaoCircular(char A[], int n, int k) {
	int posicoes=k%n;
	int primeiro=0;
	char valor1;
	char valor2;
	valor1=A[primeiro];
	int inicial=0;
	if (k==0){
		return;
	}
	for (int i=0;i<n;i++){
		int segundo=(primeiro+posicoes)%n;
		if(segundo==inicial && i!=0){ //ciclo no mesmo lugar, muda o ciclo 
			A[segundo]=valor1;
			segundo++;
			inicial=segundo;
		}
		valor2=A[segundo];
		A[segundo]=valor1;
		valor1=valor2;
		primeiro=segundo;
	}
	A[primeiro]=valor1;
}
