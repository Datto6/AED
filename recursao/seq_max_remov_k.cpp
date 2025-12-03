int Maximo(int A[], int n) {
	if(n==0){
		return 0;
	}
	else{
		int x=Maximo(A,n-1);
		if(x<A[n-1]){
			return A[n-1];
		}
		else{
			return x;
		}
	}
}

void RemoveMaiores(int L[], int &n, int k) { //remove todos maiores que k
	if (n>0){
		int tamanho=n-1;
		int x=L[n-1];
		RemoveMaiores(L,tamanho,k);
		n=tamanho; //atualizou tamanho
		if(x<=k){ //se x e menor ou igual a k, nao remove ele, e move ele pro novo fim do array, situado em n
			L[n]=x;
			n++; //aumenta o n pq acabou de colocar o x
		}
	}
}
