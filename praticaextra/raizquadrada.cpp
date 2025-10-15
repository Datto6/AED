int Calcula(int x){ //complexidade sqrt(N)
    int r=0;
    while(((r+1)*(r+1))<=x){
        r++;
        // printf(" Passo1 ");
    }
    // printf("\n");
    return r;
}

int Calcula2(int x){ //complexidade N
    int r=x;
    while((r*r)>=x){
        r--;
        // printf(" Passo2 ");
    }
    return r;
    // printf("\n");
}
int Calcula3(int x){ //complexidade log n, busca binaria
    int r=0;
    int a=x+1;
    while((r+1)!=a){
        int m=(r+a)/2;
        if (m*m<=x){
            r=m;
        }
        else{
            a=m;
        }
        // printf(" Passo3 ");
    }
    // printf("\n");
    return r;
}
