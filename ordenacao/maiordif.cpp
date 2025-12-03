int maxLista(int L[],int n){
	int max=L[0];
	for(int i=1;i<n;i++){
		if (L[i]>max){
			max=L[i];
		}
	}
	return max;
}
int minLista(int L[],int n){
	int min=L[0];
	for(int i=1;i<n;i++){
		if (L[i]<min){
			min=L[i];
		}
	}
	return min;
}
int MaiorDiferenca(int L[], int n) { //pega o maior-menor para pegar maior diferenca kkkkk uai
	int max=maxLista(L,n);
	int min=minLista(L,n);
	return max-min;
}
