void particao(int L[],int ini,int fim, int meio, int &i, int &j){
    i=ini; j=fim;
    while(i<=j){
        while(L[i]<meio)i++;
        while(L[j]>meio) j--;
        if(i<=j){
            int tmp=L[i];
            L[i]=L[j];
            L[j]=tmp;
            i++;
            j--;
        }
    }   
}

void QuickSort(int L[],int ini,int fim){
    if(ini<fim){
        int meio=L[(ini+fim)/2];
        int limfim,limini;
        particao(L,ini,fim,meio,limini,limfim);
        QuickSort(L,ini,limfim);
        QuickSort(L,limini,fim);
    }
}

int main(void){

    int coisa[]={3,425,64,-13,553};
    int tam=5;
    QuickSort(coisa,0,tam);
    for(int i=0;i<tam;i++){
        printf("%d\n",coisa[i]);
    }
    return 0;
}
