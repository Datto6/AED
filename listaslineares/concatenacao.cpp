int * Concatenar(int L1[], int n1, int L2[], int n2) { //concatena duas listas lineares sequencias 
	int* nova= (int *) malloc(sizeof(int)*(n1+n2));
	for (int i=0;i<n1;i++){
		nova[i]=L1[i];
	}
	for (int i=0;i<n2;i++){
		nova[n1+i]=L2[i];
	}
	return nova;
}
