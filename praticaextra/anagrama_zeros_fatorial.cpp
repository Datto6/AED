#include <stdio.h>
void merge(char arr[], int l, int m, int r){
    
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temp arrays
    char L[n1], R[n2];

    // Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temp arrays back into arr[l..r]
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[],
    // if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[],
    // if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// l is for left index and r is right index of the
// sub-array of arr to be sorted
void mergeSort(char arr[], int l, int r){
    
    if (l < r) {
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}
int anagrama2(char A[],char B[],int n){ //buscando cada um de A em B, incompleto porque nao considera frequencia
    for (int i=0;i<n;i++){
        if (!Busca(B,n,A[i])){
            return 0;
        }
    }
    return 1;
}
int anagrama3(char A[],char B[],int n){ //ordenando A e B e checando 
    mergeSort(A,0,n-1);
    mergeSort(B,0,n-1);
    for (int i=0;i<n;i++){
        if (A[i]!=B[i]){
            return 0;
        }
    }
    return 1;
}
long long int zeros_Fatorial(int x){ //quantos zeros no final do numero x!
    long long int zeros=0;
    int cinco=0;
    int dois=0;

    long long int cincos=5;
    while(cincos<=x){
        zeros+=x/cincos;
        cincos*=5;
    }
    return zeros;
}
