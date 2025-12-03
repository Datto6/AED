int Impar(int n) {
	// assume n >= 0
	// retorna o n-ésimo ímpar
	/* insert your code here */
	if(n==1){
		return 1;
	}
	return Impar(n-1)+2;
}

int Exp(int b, int n) {
	// assume b > 0, n >= 0
	// retorna b^n
	/* insert your code here */
	if(n==0){
		return 1;
	}
	return Exp(b,n-1)*b;
}

int Exp(int b, int n) {
	// assume b > 0, n >= 0
	// retorna b^n
	/* insert your code here */
	if(n==0){
		return 1;
	}
	if(n%2==0){
		int tmp=Exp(b,n/2);
		return tmp*tmp;
	}
	else{
		int tmp=Exp(b,(n-1)/2);
		return tmp*tmp*b;
	}
}
