void Subtrai(int A[], int n, int B[], int m, int R[], int &k) { //subtrai forma decimal de 2 numeros
	Inversor(A,n); Inversor(B,m);
	int menos=0; int i;
	for (i=0;i<n;i++){
		int total=0-menos;
		if (i<n){
			total+=A[i];
		}
		if (i<m){
			total=total-B[i];
		}
		if (total<0){
			R[i]=total+10;
			menos=1;
		}
		else {
			R[i]=total;
			menos=0;
		}
	}
	k=i;
	Inversor(R,k);
	while (R[0]==0){
		for (int j=0;j<k-1;j++){
			R[j]=R[j+1];
		}
		k--;
	}
}

//codigo abaixo representa um estado de memoria
typedef struct E1 { 
	char Nome[5];
	int Idade;
} E1;

typedef struct E2 {
	int Turma;
	E1* Aluno;
	E2* Prox;	
} E2;

void InsereFinalEnc(E2* &L, int turma, E1* aluno, E2 * &u) {
	E2 * novo = (E2 *) malloc(sizeof(E2));
	novo->Turma = turma;
	novo->Prox = NULL;
	novo->Aluno=aluno;
	if (u == NULL) {
		L = novo; 
	} else {
		u->Prox = novo;
	}
	u = novo; 
}
void TestarMemoria(int t) {
	E2* L=NULL;
	E2* ultimo=NULL;
	E1* V=(E1*) malloc(sizeof(E1)*3);
	char nome[]="JOAO";
	for (int i=0;i<4;i++){
		V[0].Nome[i]=nome[i];
	}
	V[0].Idade=5; V[1].Idade=8; 
	V[2].Idade=9;
	char nome2[]="LEO";
	for (int i=0;i<3;i++){
		V[1].Nome[i]=nome2[i];
	}
	char nome3[]="LIA";
	for (int i=0;i<3;i++){
		V[2].Nome[i]=nome3[i];
	}
	InsereFinalEnc(L,1,V,ultimo);
	InsereFinalEnc(L,1,V+1,ultimo);
	InsereFinalEnc(L,2,V+1,ultimo);
	InsereFinalEnc(L,2,V+2,ultimo);
	/* Atente para o que está sendo impresso nesse teste, e 
	   elabore o programa para ser coerente com que está sendo
	   impresso aqui! */
	if (t==1) printf("%d %d %d\n", V[0].Idade, V[1].Idade, V[2].Idade);
	if (t==2) printf("%c %c %c %c\n", V[0].Nome[0], V[0].Nome[1], V[0].Nome[2], V[0].Nome[3]);
	if (t==3) printf("%c %c %c\n", V[1].Nome[0], V[1].Nome[1], V[1].Nome[2]);
	if (t==4) printf("%c %c %c\n", V[2].Nome[0], V[2].Nome[1], V[2].Nome[2]);
	if (t==5) printf("%d %d %d %d\n", L->Turma, L->Prox->Turma, L->Prox->Prox->Turma, L->Prox->Prox->Prox->Turma);
	if (t==6) printf("%d\n", L->Prox->Prox->Prox->Prox == NULL ? 1 : 0);
	if (t==7) printf("%d %d %d %d\n", L->Aluno->Idade, L->Prox->Aluno->Idade, L->Prox->Prox->Aluno->Idade, L->Prox->Prox->Prox->Aluno->Idade);
}
