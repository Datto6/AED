int Busca(int B[], int elementos,int inicio,int alvo ){
	for (int i=inicio;i<elementos;i++){
		if (B[i]==alvo){
			return 1;
		}
	}
	return 0;
}
void SemRepeticoes(int L1[], int &N){
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


void crescente(int* &saida){ //retorna N elementos de forma crescente, quando a input sempre e ou maior q todos ou menor que todos
    int input;
    scanf("%d",&input);
    int quantidade=1;
    saida=(int *) malloc(sizeof(int)*quantidade);
    int indice=0;
    saida[0]=input;

    while(input>0){
        scanf("%d",&input);
        if (input<0){
            break;
        }
        indice++;
        quantidade++;
        if (indice>=quantidade){
            quantidade=quantidade*2;
            saida=(int*) realloc(saida,quantidade*sizeof(int));
        }
        if(input>saida[indice-1]){
            saida[indice]=input;
        }
        else{
            for (int j = indice - 1; j >= 0; j--) {
                saida[j + 1] = saida[j];
            }       
            saida[0]=input;
        }
    }
}

