#include <stdio.h> 
#include <stdlib.h>

bool ehordenada(int L[],int n,int ini,int fim){
    if(ini+1>=fim){
        return true;
    }
    else{
        bool resto=ehordenada(L,n,ini+2,fim);
        return (L[ini]<=L[ini+1]) && resto;
    }

}
    
int main(void){
    int tam=7;
    int teste[tam]={1,2,3,53,321,390,422};
    printf("%d",ehordenada(teste,tam,0,tam-1));
    return 0;
}
