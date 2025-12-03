void LerEscreverKUltimos(int k) {
	/* leia uma sequência de números (usando scanf()), e ao final (número lido é 0),
	   escreva os k últimos lidos (usando printf()). 
	   (Deixe um espaço ao final de cada número impresso.) */
	/* insert your code here */
	Fila F;
	Constroi(F);
	int n;
	while (1) {
		scanf("%d", &n);
		if(n==0){
			break;
		}
		if(Tamanho(F)<k){
			Enfileira(F,n);
		}
		else{
			Desenfileira(F);
			Enfileira(F,n);
		}
    }
	while(Tamanho(F)>0){
		printf("%d ", Desenfileira(F));
	}
	printf("\n");
}


void ManobrarVagoes(int n, int V[]) {
	Pilha M,E;
	Constroi(M); Constroi(E);
	for(int i=n;i>0;i--){
		Empilha(E,i);
	}
	for(int i=n-1;i>=0;i--){
		while((Tamanho(M)==0) || (Topo(M)<V[i])){
			Empilha(M,Desempilha(E));
			printf("E=>M,");
		}
		while(Topo(M)>V[i]){
			Empilha(E,Desempilha(M));
			printf("M=>E,");
		}
		Desempilha(M);
		printf("M=>S"); if (i>0) printf(",");
	}
	printf("\n");
	Destroi(M);Destroi(E);
}
