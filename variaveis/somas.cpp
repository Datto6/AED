#include <stdio.h>
#include <stdlib.h>

long long int CalculaSoma1(int n) {  //Soma de 1 a n [O(n)]
	/* insert your code here */
	long long int i=1;
	long long int soma=0;
	while (i<=n){
		soma=soma+i;
		i++;
	}
	return soma;
}

long long int CalculaSoma2(int n) { //soma de 1 a n [O(1)]
	/* insert your code here */
	long long int soma;
	long long int m=n;
	soma=m*(1+m)/2;
	return soma;
}

long long int CalculaSoma3(int n, int m[], int k) {  //Escreva uma função que receba como entrada um número n, um vetor
                                                      //m[], e um número k, e retorne a soma dos números entre 1 e n que
                                                      //sejam múltiplos de alguns dos números m[1],...,m[k]. [O(n)]
	/* m = [a1, a2, ..., ak] */
	/* insert your code here */
	long long int soma=0;
	long long j=k;
	for (long long int i=1; i<=n;i++){
		for (long long int indexo=0; indexo<j;indexo++){
			if (i%m[indexo]==0){
				soma+=i;
				break;
			}
		}
	}
	return soma;
}
