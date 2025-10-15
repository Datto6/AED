bool buscaBinaria(int * lista,int elementos,int alvo){
	int fim=elementos-1;
	int inicio=0;
	int meio=(fim+inicio)/2;
	while(inicio<=fim){
		if (lista[meio]>alvo){ //alvo ta na esquerda
			fim=meio-1;
		}
		if (lista[meio]<alvo){ //alvo ta na direita
			inicio=meio+1;
		}
		if(lista[meio]==alvo){
			return true;
		}
		meio=(inicio+fim)/2;
	}
	return false;
}

bool Busca(int **B, int n, int x) { //busca em matriz ordenada complexidade O(nlogn) 
	for(int i=0;i<n;i++){
		if (buscaBinaria(B[i],n,x)){ //logn para cada fileira n
			return true;
		}
	}
	return false;
}
