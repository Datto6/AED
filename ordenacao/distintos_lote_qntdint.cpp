int Distintos(int L[], int N) {
	Ordenar(L,N); //o log n
	int distintos=0;
	for (int i=0;i<N-1;i++){
		if(L[i]!=L[i+1]){
			distintos++;
		}
	}
	distintos++;
	return distintos;
}
int BuscaEmLote(int L[], int B[], int n) {
	Ordenar(L,n);
	int saida=0;
	for(int i=0;i<n;i++){
		if(buscaBinaria(L,n,B[i])){
			saida++;
		}
	}
	return saida;
}
int BuscaBinaria(int L[], int n, int x){ //retorna o indice do x 
	int fim=n;
	int ini=0;
	int meio=(ini+fim)/2;
	while(ini<=fim){
		meio=(ini+fim)/2;
		if(L[meio]==x){
			return meio;
		}
		else if(L[meio]>x){
			fim=meio-1;
		}
		else{
			ini=meio+1;
		}
	}
	return ini;
}

int QuantidadeIntervalo(int L[], int n, int a, int b) { // quantidade no intervalo entre a e b 
	int indiceA=BuscaBinaria(L,n,a); //aponta pra onde busca para ao procurar a, a seria inserido 1 indice atras
	int indiceB=BuscaBinaria(L,n,b+1)-1; //primeiro indice maior que b menos 1--> aponta pra limite 
	return (indiceB-indiceA)+1;
}
