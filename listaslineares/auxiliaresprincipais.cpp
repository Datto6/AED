int Busca(No* coisa,int x){
    No* p=coisa;
    while(p!=NULL){
        if(p->E==x){
            return 1; //achou, logo contem e true
        }
        p=p->Prox;
    }
    return 0; //nao achou, logo nao contem
}

void InsereInicioEnc(No * &L, long long int e) { //funcoes auxiliares 
	No * novo = (No *) malloc(sizeof(No));
	novo->E = e; novo->Prox = L; L = novo; 
}

void InsereEnc(No * &L, int e, No * &u) {  //final
	No * novo = (No *) malloc(sizeof(No));
	novo->E = e; novo->Prox = NULL; 
	if (u == NULL) {
		L = novo; 
	} else {
		u->Prox = novo;
	}
	u = novo; 
}
