No * Soma2a2(No * L) {
	No* p1=L;
	No* p2=NULL;
	No* novo=NULL;
	No* u=NULL;
	while(p1!=NULL){
		p2=p1->Prox;
		while(p2!=NULL){
			Inserefim(novo,(p2->E+p1->E),u);
			p2=p2->Prox;
		}
		p1=p1->Prox;
	}
	return novo;
}
