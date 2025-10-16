No * Soma2a2(No * L) {
// retorna todos os valores somados 2 a 2, 1->5->4->10 retorna 6->5->11->9->15->14
	No* p1=L;
	No* p2=NULL;
	No* novo=NULL;
	No* u=NULL;
	while(p1!=NULL){
		p2=p1->Prox;
		while(p2!=NULL){ //caminha a partir de proximo, somando sempre o mesmo p1
			Inserefim(novo,(p2->E+p1->E),u);
			p2=p2->Prox;
		}
		p1=p1->Prox;
	}
	return novo;
}
