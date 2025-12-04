#include <stdio.h> 
#include <stdlib.h>

int produto(int a, int b){
    if(b==0){
        return 0;
    }
    if(b%2==0){
        int x=produto(a,b/2);
        return x+x;
    }
    else{
        return produto(a,b-1)+a;
    }
}
    
int main(void){
    printf("%d\n",produto(5,5));
    return 0;
}
