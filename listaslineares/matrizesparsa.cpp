typedef struct No {
	int col;
	int E;
	No * Prox;
} No;

typedef struct MatrizEsparsa {
	int N;
	No ** linhas; //linhas[i] uma lista encadeada dos valores 
	              //não nulos da matriz na linha i
} MatrizEsparsa;

void InsereEnc(No * &L, int col, int e, No * &u) { //funcao auxiliar ja reusada a um tempo
	No * novo = (No *) malloc(sizeof(No));
	novo->col = col; novo->E = e; novo->Prox = NULL; 
	if (u == NULL) {
		L = novo; 
	} else {
		u->Prox = novo;
	}
	u = novo; 
}

int ObtemElemMatriz(MatrizEsparsa M,int linha,int coluna){ //funcao auxiliar
	No* p=M.linhas[linha];
	while (p!=NULL){
		if (p->col==coluna){
			return p->E;
		}
		p=p->Prox;
	}
	return 0;
}

int MultiplicaLinhaColuna(MatrizEsparsa M, int i, int j){ //funcao auxiliar
	int soma=0;
	No* p=M.linhas[i];
	while (p!=NULL){
		int elemlinha=p->E;
		soma+= elemlinha*ObtemElemMatriz(M,p->col,j);
		p=p->Prox;
	}
	return soma;
}

MatrizEsparsa AoQuadrado(MatrizEsparsa M) { //multiplicacao de matrizes esparsas Theta N^2
	MatrizEsparsa nova;
	int ordem=M.N;
	nova.N=M.N;
	nova.linhas = (No **) malloc(sizeof(No *)*M.N);
	for (int i=0;i<ordem;i++){
		nova.linhas[i]=NULL;
		No* ultimo=NULL;
		for (int j=0;j<ordem;j++){
			int valor=MultiplicaLinhaColuna(M,i,j);
			if (valor!=0){
				InsereEnc(nova.linhas[i],j,valor,ultimo);
			}
		}
	}
	return nova;
}
