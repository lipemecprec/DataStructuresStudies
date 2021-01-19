// FLIPERAM - Fliperama - https://br.spoj.com/problems/FLIPERAM/

#include <stdio.h>

int NMAX = 10010, MMAX = 510;
int N, M; //  N  quantas partidas foram jogadas de Bebe-bebe , M quantas linhas cabem no mostrador de melhores rankings.
int v[10010];
int aux[10010];

void mergeSort(int l , int r);

int main() {

int i = 0;

    do{
        scanf("%d %d ", &N, &M);
    }while(N==0);
    
    for ( i = 0 ; i <= N ; i++) {
        scanf("%d ", &v[i]);
    }
    // printf("N=%d M=%d i=%d \n", N, M, i);
    
    mergeSort(0 , N);
    
    for ( i = 0 ; i < M; i++) {
        printf ("%d \n", v[i]);
    }
    
}

void mergeSort(int l , int r){
    
    if (l == r) return;
    
    int mid =  (l + r)/2;
    
    mergeSort(l , mid);
    mergeSort(mid + 1 , r);
    
    int posl = l;
    int posr = mid + 1;
    int posAux = l;
    
    while( posl <= mid && posr <= r){
        if (v[posl]>=v[posr]) aux[posAux++]=v[posl++];
        else aux[posAux++]=v[posr++];
    }
    while(posl <= mid){
        aux[posAux++]=v[posl++];
    }
    while(posr <= r){
        aux[posAux++]=v[posr++];
    }
    
    for(int i = 0 ; i <= r; i++){
        v[i] = aux[i];
    }
}