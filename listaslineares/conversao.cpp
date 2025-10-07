void insereultimo(NoEnc* &L, int chave, int E, NoEnc* &ultimo){
	NoEnc* novo= (NoEnc *) malloc(sizeof(NoEnc));
	novo->Chave=chave;
	novo->E=E;
	novo->Prox=NULL;
	if (ultimo==NULL){
		L=novo;
	}
	else{
		ultimo->Prox=novo;
	}
	ultimo=novo;
}

NoEnc * ConverterSeqParaEnc(NoSeq L[], int N) {
	NoEnc* saida=NULL;
	NoEnc* ultimo=NULL;
	for (int i=0;i<N;i++){
		insereultimo(saida,L[i].Chave,L[i].E,ultimo);
	}
	return saida;
}

NoSeq * ConverterEncParaSeq(NoEnc * L, int &N) {
	NoEnc* p=L;
	N=0;
	while (p!=NULL){
		N++;
		p=p->Prox;
	}
	p=L;
	NoSeq* saida= (NoSeq*) malloc(sizeof(NoSeq)*N);
	for (int i=0;i<N;i++){
		saida[i].Chave=p->Chave;
		saida[i].E=p->E;
		p=p->Prox;
	}
	return saida;
}
