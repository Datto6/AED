#include <stdio.h> 
#include <stdlib.h>
typedef struct No{
    int E;
    No* Prox;
}No;
void InsereInicioEnc(No * &L, long long int e) { //funcoes auxiliares 
	No * novo = (No *) malloc(sizeof(No));
	novo->E = e; novo->Prox = L; L = novo; 
}

void InsereEnc(No * &L, int e, No * &u) {  //Enc
	No * novo = (No *) malloc(sizeof(No));
	novo->E = e; novo->Prox = NULL; 
	if (u == NULL) {
		L = novo; 
	} else {
		u->Prox = novo;
	}
	u = novo; 
}
void exibe(No* coisa){
    No* p=coisa;
    while(p!=NULL){ //enquanto nao chegou ao final
        printf("%d",p->E);
        p=p->Prox;
        if (p!=NULL) printf(" ->"); 
    }
    printf("\n");
}

// retorna o tamanho da seq crescente iniciando em L
int CRec(No* L, No* primeiro, int &MSeqIni, int &MSeq) {
    // caso base: lista vazia
    if (L == NULL)
        return 0;
    // caso base: último nó
    if (L->Prox == NULL) {
        // maior seq global é 1 por enquanto
        MSeq = 1;
        // sequência inicial também é 1 (só o primeiro)
        if (L == primeiro)
            MSeqIni = 1;
        return 1;
    }
    int MSeqIniSub, MSeqSub;

    // recursão para o próximo nó
    int lenSub = CRec(L->Prox, primeiro, MSeqIniSub, MSeqSub);
    int len;
    if (L->Prox->E > L->E){
        len = 1 + lenSub;
    }
    else{
        len = 1;
    }
    // atualiza maior sequência global
    MSeq = (len > MSeqSub ? len : MSeqSub);

    // atualiza a sequência inicial somente no primeiro nó
    if (L == primeiro){
        MSeqIni = len;
    }
    else{
        MSeqIni = MSeqIniSub;
    }
    return len;
}

void C(No* L, int &MSeqIni, int &MSeq) {
    if (L == NULL) {
        MSeqIni = 0;
        MSeq = 0;
        return;
    }
    CRec(L, L, MSeqIni, MSeq);
}

int main(void){
    No* cabeca=NULL;
    No* ultimo=NULL;
    InsereEnc(cabeca,1,ultimo); InsereEnc(cabeca,3,ultimo);
    InsereEnc(cabeca,5,ultimo); InsereEnc(cabeca,2,ultimo);
    InsereEnc(cabeca,3,ultimo); InsereEnc(cabeca,7,ultimo);
    InsereEnc(cabeca,5,ultimo); InsereEnc(cabeca,6,ultimo);
    InsereEnc(cabeca,1,ultimo); InsereEnc(cabeca,2,ultimo);
    InsereEnc(cabeca,3,ultimo); InsereEnc(cabeca,4,ultimo);
    exibe(cabeca);
    int SeqIni,MSeq;
    C(cabeca,SeqIni,MSeq);
    printf("%d\n",SeqIni);
    printf("%d\n",MSeq);
    return 0;
}
