# include <stdio.h>

int AchaKCirculo(int vec[],int N){ //logica do professor
    int i=0;
    int j=N-1;
    int k;
    while(i<=j){
        k=(i+j)/2;
        if((k>0 && vec[k]<vec[k-1]) || (k==0 && vec[0]<vec[N-1])){ //condicao de termos achado o k 
            break;
        }
        else{
            if(vec[k]<vec[j-1]){ //k ta na direita 
                j=k-1;
            }
            else{
                i=k+1; //k na esquerda 
            }
        }
    }
    return k;
}
int AchaKCirculo(int vec[], int N) { //busca binaria igual, so que para achar o k
    int i = 0, j = N - 1;
    while (i < j) {
        int mid = (i + j) / 2;
        if (vec[mid] > vec[j])
            i = mid + 1;
        else
            j = mid;
    }
    return i;
}
int BuscaBinariaCircular(int vec[], int N, int elem){ // pega o k com funcao auxiliar
    int ps_fim=N-1; //int fim=(k-2)%N;  
    int ps_inicio=0; //int inicio=k-1;
    int ps_meio=(ps_inicio+ps_fim)/2; //int meio=(inicio+(fim+inicio)/2)%N
    int k=AchaKCirculo(vec,N);
    printf("%d\n",k);
    int r_meio=(ps_meio+k)%N;
    while(ps_inicio<=ps_fim){
        if (vec[r_meio]==elem){
            return r_meio;
        }
        else if(vec[r_meio]<elem){
            ps_inicio= ps_meio+1;   // inicio=(N+meio+1)%N;
        }
        else{
            ps_fim=ps_meio-1;   //fim=(N+meio-1)%N;
        }

        ps_meio=(ps_inicio+ps_fim)/2;
        r_meio=(ps_meio+k)%N;
        // meio=(inicio+(fim+inicio)/2)%N;
    }
    if (vec[k-1]==elem){
        return k-1;
    }
    else{
        return 0;
    }
}

int main(void){
    int A[]={3, 4, 5, 6, 7,8 , 9, 10, 11, 12,13,14, 1, 2};
    int n=14;
    int elemento=21;
    int saida=BuscaBinariaCircular(A,n,elemento);
    printf("%d\n",saida);
    return 0;
}
