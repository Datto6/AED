long long int Bin(int n, int k) {
	// assume n >= k >= 0
	// retorna binomial de n,k = n! / (k! (n-k)!)
	/* insert your code here */
	if (k==0){
		return 1;
	}
	else{
		return (long long int) (Bin(n-1,k-1)*n)/k;
	}
}
int RaizQuad(int n) {
	// assume n >= 0
	// retorna r tal que r^2 <= n < (r+1)^2
	/* insert your code here */
	if (n>=1){
		int x=RaizQuad(n-1);
		int xquad=(x+1)*(x+1);
		if((xquad>n-1) && xquad==n){ //se o quadrado da raiz quadrada+1 e maior que n-1, e eh igual a n original, entao a raiz quadrada e de fato x+1 
			return x+1;
		}
		else{
			return x; //se nao, ta no intervalo correto
		}
	}
	else{
		return 0;
	}
}

int RaizQuad(int i, int f, int n){ //busca binaria de raiz quadrada , tempo logn
	long long int meio=(i+f)/2;
	long long int meioquad=(long long) meio*meio;
	long long int meiomaior=(long long) (meio+1)*(meio+1);
	if(i+1==f){
		return i;
	}
	else{
		if (meioquad<=n && meiomaior>n){
			return meio;
		}
		else if( (meioquad)>n){
			return RaizQuad(i,meio,n);
		}
		else{
			return RaizQuad(meio,f,n);
		}
	}
}

int RaizQuad(int n) {
	// assume n >= 0
	// retorna r tal que r^2 <= n < (r+1)^2
	// retorna ⌊√(n)⌋
	/* insert your code here */
	return RaizQuad(0,n+1,n);
}
