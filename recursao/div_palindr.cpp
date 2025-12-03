int Divisores(int n, int k) { //quantos divisores de n menores que k?
	if (k==0){ //caso base
		return 0;
	}
	else{
		int num_ant=Divisores(n,k-1);
		if (n%k==0){
			num_ant++;
			return num_ant;
		}
		else{
			return num_ant;
		}
	}
}

bool EhPalindromo(char C[], int i, int f) { //retorna se um vetor de caracteres e palindromo ou nao
	if(f<i){
		return true;
	}
	else{
		if (C[i]!=C[f-1]){
			return false;
		}
		else{
			return EhPalindromo(C,i+1,f-1);
		}
	}
}
bool EhPalindromo(char C[], int n) {
	return EhPalindromo(C,0,n);
}
