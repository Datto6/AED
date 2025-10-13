bool InsereBuscaRemove(No * L, int x) { //retorna true se dobro de x ta la, insere x, remove triplo. Lista encadeada ordenada
	No* p=L->Prox;
	No* pAnt=L;
	bool dobro=false;
	bool inserido=false;
	while (p->Prox!=NULL){
		if (p->E>x && !inserido){
			No* novo= (No*) malloc(sizeof(No));
			novo->E=x;
			novo->Prox=p;
			pAnt->Prox=novo;
			inserido=true;
			pAnt=novo;
		}
		if (p->E==2*x){
			dobro=true;
		}
		if (p->E==3*x){
			pAnt->Prox=p->Prox;
			free(p);
			p=pAnt->Prox;
		}
		else{
			pAnt=p;
			p=p->Prox;
		}

	}
	if (!inserido) {
        No* novo = (No*) malloc(sizeof(No));
        novo->E = x;
        novo->Prox = p;     // p está no cauda
        pAnt->Prox = novo;
    }
	return dobro;
}
ListaLinear Diferenca(ListaLinear L1, ListaLinear L2) { //retorna L3 com elementos de L1 que nao estao em L2
	ListaLinear L3;
	L3.N=0; 
	L3.Inicio=NULL;   //inicializacao de L3
	No* procurador=L1.Inicio;
	No* ultimoNo=NULL;
	while(procurador!=NULL){ 
		int elemento=procurador->E;
		if (!Busca(L2,elemento)){
			Insere(L3,elemento,ultimoNo);
		}
		procurador=procurador->Prox;
	}
	return L3;
}
ListaLinear Intersecao(ListaLinear L1, ListaLinear L2) {
  //retorna L3 com intersecao entre L1 e L2
	ListaLinear L3;
	L3.N=0;
	int max=L1.N+L2.N;
	L3.E= (int *) malloc(sizeof(int)*max);
	for (int i=0;i<L1.N;i++){
		int elemento= L1.E[i];
		if (Busca(L2,elemento)){
			Insere(L3,elemento);
		}
	}
	return L3;
}
