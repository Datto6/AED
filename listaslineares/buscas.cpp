bool buscaBinaria(int * lista,int elementos,int alvo){
	int fim=elementos-1;
	int inicio=0;
	int meio=(fim+inicio)/2;
	while(inicio<=fim){
		if (lista[meio]>alvo){
			fim=meio-1;
		}
		if (lista[meio]<alvo){
			inicio=meio+1;
		}
		if(lista[meio]==alvo){
			return true;
		}
		meio=(inicio+fim)/2;
	}
	return false;
}

bool Busca(int **B, int n, int x) { //busca em matriz ordenada complexidade O(nlogn) 
	for(int i=0;i<n;i++){
		if (buscaBinaria(B[i],n,x)){
			return true;
		}
	}
	return false;
}

int BuscaBinariaCircular(int vec[], int N, int elem, int k){ // parametro k o minimo, vetor sequencial ordenado de forma circular comecando em k-esimo 
    int ps_fim=N-1; //int fim=(k-2)%N;  
    int ps_inicio=0; //int inicio=k-1;
    int ps_meio=(ps_inicio+ps_fim)/2; //int meio=(inicio+(fim+inicio)/2)%N
    int r_meio=(ps_meio+k)%N;
    while(ps_inicio<=ps_fim){
        if (vec[r_meio]==elem){
            return r_meio;
        }
        else if(vec[r_meio]<elem){
            ps_inicio= ps_meio+1;   // inicio=(N+meio+1)%N;
            printf("%d inicio ",ps_inicio); 
        }
        else{
            printf("%d fim1 ",ps_fim);
            ps_fim=ps_meio-1;   //fim=(N+meio-1)%N;
            printf("%d fim2 ",ps_fim);
        }
        printf("%d meio1 ",r_meio);
        ps_meio=(ps_inicio+ps_fim)/2;
        r_meio=(ps_meio+k)%N;
        // meio=(inicio+(fim+inicio)/2)%N;
        printf("%d meio2 ",r_meio);
        printf("\n");
    }
    if (vec[k-1]==elem){
        return k-1;
    }
    else{
        return 0;
    }
}
