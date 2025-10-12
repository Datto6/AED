# include <stdio.h>

int Busca(int B[], int elementos,int inicio,int alvo ){ 
	for (int i=inicio;i<elementos;i++){
		if (B[i]==alvo){
			return 1;
		}
	}
	return 0;
}
void SemRepeticoes(int L1[], int &N){ //lista sequencial, retorna sem repeticoes, complexidade O(n^2) com espaco auxiliar constante
    int p=0;
	int i=0;
	while (i<N-1){
		if (Busca(L1,N,i+1,L1[i])){
			L1[i]=L1[N-1];
			--N;
		}
		else{
			i++;
		}
	}
}

No * SemRepeticoes(No * L) { //lista encadeada, mesmo retorno e complexidade so que espaco auxiliar O(n)
	No* p=L;
	No* novo=NULL;
	while (p!=NULL){
		if (!Busca(novo,p->E)){
			Insere(novo,p->E);
		}
		p=p->Prox;
	}
	return novo;
}

No * SemRepeticoes(No * L) {
	No* p=L;
	No* pAnt=NULL;
	while (p!=NULL){
		No* prox=p->Prox;
		if (Busca(prox,p->E)){
			removeEncadeada(L,p,pAnt);
		}
		else{
			pAnt=p;
		}
		p=prox;
	}
	No* novo=NULL;
	while (p!=NULL){
		Insere(novo,p->E);
		p=p->Prox;
	}
	return novo;
}
