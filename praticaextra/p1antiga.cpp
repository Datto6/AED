#include <stdio.h>
#include <stdlib.h>
double Variancia(int n, int arr[]){
    double media=0;
    for (int i=0;i<n;i++){
        media+= (double) arr[i];
    }
    media=(double) media/n;
    double variancia=0;
    for (int i=0;i<n;i++){
        double desvio=(double) media-arr[i];
        variancia+=desvio*desvio;
    }
    return variancia/n;
}

typedef struct No{
    int E;
    No* Prox;
}No;

void remove(int arr[],int& n,int x){
    int i=0;
    int remove=0;
    while (arr[i]<=x){
        if (arr[i]==x){
            remove++;
        }
        i++;
    }
    for(int j=i;j<n;j++){
        arr[j-remove]=arr[j];
    }
    n=n-remove;
    printf("%d ",n);
}

int AcimaMedia(No* L){
    int media=0;
    No* p=L;
    int contador=0;
    int quantidade=0;
    while (p!=NULL){
        media+=p->E;
        p=p->Prox;
        quantidade++;
    }
    media=media/quantidade;
    p=L;
    while(p!=NULL){
        if (p->E>media){
            contador++;
        }
    }
    return contador;
}
void InsereUltimo(No* &L, No* &ultimo,int x){
    No* novo=(No*) malloc(sizeof(No*));
    novo->E=x;
    novo->Prox=NULL;
    if(ultimo==NULL){
        L=novo;
    }
    else{
        ultimo->Prox=novo;
    }
    ultimo=novo;
}
No* SomenteNegativo(No* L){
    No* novo=NULL;
    No* ultimo=NULL;
    No* p=L;
    while(p!=NULL){
        if (p->E<0){
            InsereUltimo(novo,ultimo,p->E);
        }
        p=p->Prox;
    }
    return novo;
}

int main(void){
    // int teste[]={1,5,5,5,-234};
    // printf("%lf\n",Variancia(5,teste));
    int teste2[]={1,2,3,4,5,6,6,6,6,7,8,9,10,12,13};
    int num=sizeof(teste2)/sizeof(int);
    remove(teste2,num,6);
    No* p=NULL;
    No* ultimo=NULL;
    remove(teste2,num,5);
    for(int i=0;i<num;i++){
        printf("%d ", teste2[i]);
    }
    printf("\n");
    // printf("%d",AcimaMedia());
    return 0;
}
