#include <stdio.h>
#include <stdlib.h>

typedef struct FilaPrioridade{
    int* E;
    int N;
}FilaPrioridade;
void Constroi(FilaPrioridade &F, int Tmax){
    F.E=(int* )malloc(sizeof(int)*(Tmax+1));
    F.N=0;
}
int Maior(FilaPrioridade F){
    return F.E[0];
}
void sobe(FilaPrioridade &F, int i){
    int p=i/2;
    int f=i;
    while((f>1)&& (F.E[p]<F.E[f])){
        int t=F.E[p];
        F.E[p]=F.E[f];
        F.E[f]=t;
        f=p;
        p=f/2;
    }
}
void InserePrioridade(FilaPrioridade &F,int x){
    F.E[F.N+1]=x;
    F.N++;
    sobe(F,F.N);
}
void Desce(FilaPrioridade &F, int p){
    int f1=2*p;
    int f2=2*p+1;
    while(1){
        if(f1>F.N) break;
        int f=((f2>F.N) || (F.E[f1]>=F.E[f2]) ? f1 : f2);
        if(F.E[p]>=F.E[f])break;
        int t=F.E[p];
        F.E[p]=F.E[f];
        F.E[f]=t;
        p=f;
        f1=2*p;
        f2=2*p+1;
    }
}

int RemovePrioridade(FilaPrioridade &F){
    int x=Maior(F);
    F.E[1]=F.E[F.N];
    F.N=F.N-1;
    Desce(F,1);
    return x;
}
