void Inverter(int L[], int n) { //inverte lista sequencial
	for (int i=0;i<n/2;i++){
		int tmp=L[i];
		L[i]=L[n-i-1];
		L[n-i-1]=tmp;
	}
}
long long int ParesIguais(int A[], int B[], int n) { //quantos pares de valores entre A e B, O(n)
	int contA=0;
	int contB=0;
	long long int contador=0;
	while (contA<n){
		long long int elemento=A[contA];
		long long int parA=0;
		long long int parB=0;
		if(elemento==B[contB]){
			while(B[contB]==elemento){
				parB++;
				contB++;
			}
			while(A[contA]==elemento){
				parA++;
				contA++;
			}
			contador= (long long int) contador+parA*parB;
		}
		else if (elemento>B[contB]){
			contB++;
		}
		else{
			contA++;
		}
	
	}
	return contador;
}
