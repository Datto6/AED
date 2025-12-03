No * ExpressaoParaArvore(char C[], int ini, int fim) {
	//converter a expressão parentizada C[ini..fim]
	/* insert your code here */
	No* novo=(No* ) malloc(sizeof(No));
	if (C[ini]=='('){
		int fim1=0;
		int nivel=1;
		for (int i = ini+1; i < fim; i++) {
			if (C[i] == '(') nivel++;
			else if (C[i] == ')') nivel--;
			else if ((C[i]=='+' || C[i]=='-' || C[i]=='*' || C[i]=='/') && nivel == 1) {
				fim1 = i;
				break;   // operador principal encontrado
			}
		}
		fim1--;
		//chega ate ultimo antes de expressao acabar
		novo->op=C[fim1+1];
		novo->Esq=ExpressaoParaArvore(C,ini+1,fim1);
		novo->Dir=ExpressaoParaArvore(C,fim1+2,fim-1);
	}
	else{
		novo->op='@';
		novo->Esq=NULL;
		novo->Dir=NULL;
		novo->E= C[ini] - '0';
	}
	return novo;
}

int AvaliarExpressao(No * T) {
	/* insert your code here */
	switch(T->op){
		case '+':
			return AvaliarExpressao(T->Esq)+ AvaliarExpressao(T->Dir);
			break;
		case '*':
			return (int) AvaliarExpressao(T->Esq)*AvaliarExpressao(T->Dir);
			break;
		case '-':
			return (int) AvaliarExpressao(T->Esq)-AvaliarExpressao(T->Dir);
			break;
		case '/':
			return (int) AvaliarExpressao(T->Esq)/AvaliarExpressao(T->Dir);
			break;
		default:
			return T->E;
			break;
	}
}
