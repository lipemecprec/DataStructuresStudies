// B. Less or Equal - https://codeforces.com/group/8aYPdJMcRz/contest/310840/problem/B

#include <stdio.h>

int N, K; //  N  number of entries , K value to compare.
long long int v[200010];
long long int aux[200010];

void mergeSort(int l , int r);

int main() {

int i = 0;

    do{
        scanf("%d %d ", &N, &K);
    }while(N==0);
    
    for ( i = 0 ; i <= N ; i++) {
        scanf("%lld ", &v[i]);
    }
    
    mergeSort(0 , N);
    
    if(K==0){
        if(v[1]==1)printf("-1");
        else printf("1");
    }else if(K==N){
        printf("%lld",v[K]);  
    }else if(v[K+1]>v[K]){
        printf("%lld",v[K]);
    }else{
        printf("-1");
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
        if (v[posl]<=v[posr]) aux[posAux++]=v[posl++];
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