# include <stdio.h> 
#define dimensao 5


void Transposta(int B[][dimensao], int n){ //fazer a transposta rotaciona 90 graus sentido anti horario
    for (int i=0;i<n;i++){
        for (int j=i+1;j<n;j++){//comecando a partir da diagonal principal, se nao troca duas vezes e fica a mesma coisa
            int tmp =B[i][j];
            B[i][j]=B[j][i];
            B[j][i]=tmp;
        }
    }
}
void Inversor(int B[],int n){ //inversor de linha
    for (int i=0;i<n/2;i++){
        int tmp=B[i];
        B[i]=B[n-i-1];
        B[n-i-1]=tmp;
    }
}
void RotacionarHorario(int B[][dimensao], int n){ //rotaciona bitmap 90 graus sentido horario
    Transposta(B,n);
    for (int i=0;i<n;i++){ 
        Inversor(B[i],n);
    }

}


void Insere_MemX(char A[],int &tamanhoA,char B[],int tamanhoB, char x){ //insere um vetor dentro de cada ocorrencia de um char x
    for (int i=0;i<tamanhoA;i++){
        if(A[i]==x){
            for (int k=0;k<tamanhoB-1;k++){
                for (int j=tamanhoA;j>i;j--){
                    A[j+1]=A[j];
                }
            }
            for (int k = 0; k < tamanhoB; k++) {
                A[i+k] = B[k];
            }
            tamanhoA+=tamanhoB-1;
            i+=tamanhoB-1;
        }
    }
}
