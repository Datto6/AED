void Remove(No * &L, No * p) { //remocao de lista duplamente encadeada, tempo constante
	if(p==L){
		L=p->Prox;
	}
	if(p->Ant!=NULL){
		p->Ant->Prox=p->Prox;
	}
	if (p->Prox!=NULL){
		p->Prox->Ant=p->Ant;
	}
	free(p);
}

void Remove(No * &L, No * p) { //remocao de lista simplesmente encadeada, tempo O(n)
	No* q=L;
	No* qAnt=NULL;
	while (q!=NULL){
		if (q==p){
			if (qAnt==NULL){
				L=p->Prox;
			}
			else{
				qAnt->Prox=q->Prox;
			}
			break;
		}
		else{
			qAnt=q;
			q=q->Prox;
		}

	}
	free(p);
}

void RemoveMaiores(No * &L, int k) { //remove todos os elementos maiores que k, encadeada
	No* p=L;
	No* pAnt=NULL;
	while (p!=NULL){
		if (p->E<=k){
			pAnt=p;
			p=p->Prox;
		}
		else{
			if (pAnt==NULL){
				L=p->Prox;
			}
			else{
				pAnt->Prox=p->Prox;
			}
			free(p);
			if (pAnt==NULL){
				p=L;
			}
			else{
				p=pAnt->Prox;
			}
		}

	}
}
void RemoveMaiores(int L[], int &n, int k) { //remove todos maiores que k, sequencial
	int i=0;
	while (i<n){ //comeca na posicao 0 ate N
		if(L[i]>k){  //checo se numero atual e maior que k
			L[i]=L[n-1];  //remocao sobre escrevendo ultimo valor no atual
			n--;  //"apagando" ultimo reduzindo indice
		}
		else{  //se nao precisa apagar, seguir p proximo
			i++;
		}
	}
}
