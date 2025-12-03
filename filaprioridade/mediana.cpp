typedef struct Mediana {
	double med; //mediana
	int n; //número de elementos inseridos
	FilaPrioridade ante; //antecedes a mediana (maxheap)
	FilaPrioridade post; //posteriores a mediana (minheap)
} Mediana;

double ObterMediana(Mediana &C) {
	/* insert your code here */
	if(C.n%2==0){
		return (double) (Topo(C.ante)+(-Topo(C.post)))/2;
	}
	else{
		if(Tamanho(C.ante)>Tamanho(C.post)){
			return (double) Topo(C.ante);
		}
		else{
			return (double) -Topo(C.post);
		}
	}
	return C.med;
}

void Insere(Mediana &C, int x) {
	/* insert your code here */
	if(C.n==0){
		Enfileira(C.ante,x);
		C.med=(double) x;
	}
	else if(x>C.med){
		Enfileira(C.post,-x); //na real ambos sao maxheap, entao tenho que inverter sinais
	}
	else{
		Enfileira(C.ante,x);
	}
	C.n++;
	if(Tamanho(C.post)-Tamanho(C.ante)>1){
		Enfileira(C.ante,-Desenfileira(C.post));
	}
	else if(Tamanho(C.ante)-Tamanho(C.post)>1){
		Enfileira(C.post,-Desenfileira(C.ante));
	}
	C.med=ObterMediana(C);
}
