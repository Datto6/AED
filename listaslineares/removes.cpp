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
