bool ProcuraSoma(int L[], int n, int k) { //ve se da p pegar dois elementos tal que soma de k
	Ordenar(L,n);
	for(int i=0;i<n;i++){
		if(buscaBinaria(L,n,k-L[i])){
			return true;
		}
	}
	return false;
}

int SomaMaisProximaZero(int L[], int n) { //soma mais perto de zero, ordena por valor absoluto e checa valor y para pegar soma mais perto de 0 
	Par* coisa=(Par*) malloc(sizeof(Par)*n);
	for(int i=0;i<n;i++){
	coisa[i].x=abs(L[i]);
		coisa[i].y=L[i];
	}
	Ordenar(coisa,n);
	int soma=coisa[0].y+coisa[1].y;
	for(int i=1;i<n-1;i++){
		int dif=abs(coisa[i].x-coisa[i+1].x);
		int real=abs(coisa[i].y+coisa[i+1].y);
		if(dif<soma && real<soma ){
			soma=real;
		}
	}
	return soma;
}
