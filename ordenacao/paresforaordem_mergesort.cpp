void Merge(int L[],int ini,int m, int fim, int &inv){
	int N=fim-ini+1;
	int * T=(int* )malloc(sizeof(int)*N);
	int i=ini; int j=m+1;
	int k=0;

	// for (int k=0; k<N; k++){
	while(i<=m || j<=fim){
		if((j>fim)|| ((i<=m) && (L[i]<=L[j]))){
			T[k]=L[i];
			i++;
		}
		else{
			T[k]=L[j];
			j++;
			inv=inv+(m-i+1); //o numero de pares invertidos e o numero de pares no lado esquerdo que ainda nao foram colocados, expresso por (m-i+1)
		}
		k++;
	}
	for (int i=0; i<N; i++) {
		L[ini+i] = T[i];
	}
	free(T);
}
void MergeSort(int L[], int ini, int fim, int &inv){
	if(ini<fim){
		int m=(ini+fim)/2;
		MergeSort(L,ini,m,inv);
		MergeSort(L,m+1,fim,inv);
		Merge(L,ini,m,fim,inv);
	}
}
int ParesForaOrdem(int L[], int n) { // retorna numero de pares fora de ordem, apenas com o inv num dos passos do merge sort
	int inv=0;
	MergeSort(L,0,n-1,inv);
	return inv;
}
