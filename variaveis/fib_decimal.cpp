int Fibonacci(int n) { //retorna n-esimo numero de fibonacci 
	long int n1=0;
	long int n2=1;
	long n3;
	for (int i=3;i<=n;i++){
		n3=(n1+n2)%1000000000;
		n1=n2%1000000000;
		n2=n3%1000000000;
	}
	if (n==1){
		return n1;
	}
	if (n==2){
		return n2;
	}
	return n3;
}

void RepresentacaoDecimal(long long int n, int R[], int & k) { //retorna representacao decimal
	int i=0;
	k=0;
	if (n == 0) {          // caso n = 0
        R[0] = 0;
        k = 1;
        return;
    }
	while (0<n){ //pega 7023--> [3,2,0,7]
		R[i]=(int) (n%10);
		n=(long long int) n/10;
		i++;
		k+=1;
	}
	for (int i = 0; i < k/2; i++) { //inverte o vetor, k numero de elementos (tome como definicao de inversor)
        int tmp = R[i];
        R[i] = R[k - 1 - i];
        R[k - 1 - i] = tmp;
    }
}

void Soma(int A[], int n, int B[], int m, int R[], int &k) {
	Inversor(A,n); Inversor(B,m);
	int adicional=0; int i;
	for (i=0;i<n;i++){
		int soma=adicional;
		if (i<m){
			soma+=B[i];
		}
		if (i<n){
			soma+=A[i];
		}
		if (soma>=10){
			R[i]=soma%10;
			adicional=1;
		}
		else {
			R[i]=soma;
			adicional=0;
		}
	}
	if (adicional){
		R[i]=1;
		i++;
	}
	k=i;
	Inversor(R,k);
}
