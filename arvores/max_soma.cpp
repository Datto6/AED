int max(int x,int y, int z){
	if(x>y && x>z){
		return x;
	}
	else if(y>z){
		return y;
	}
	else{
		return z;
	}
}
int Maior(No * T) { //retorna maior elemento de uma arvore
	if(T==NULL){
		return 0;
	}
	else{
		int x=Maior(T->Esq);
		int y=Maior(T->Dir);
		return max(x,y,T->E);
	}
}

int SomaFolhas(No * T) { //retorna a soma das folhas 
	if(T==NULL){
		return 0;
	}
	else{
		if(T->Dir==NULL && T->Esq==NULL){
			return T->E;
		}
		return SomaFolhas(T->Dir)+SomaFolhas(T->Esq);
	}
}
