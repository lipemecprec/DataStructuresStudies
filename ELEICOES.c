// https://br.spoj.com/problems/ELEICOES/
#include <stdio.h>

int main(){
    int N; //votes qty
    long long int x[1000000010] = {}, v;
    
    scanf("%d ", &N);
    
    for(int i = 1 ; i <= N ; i++){
        scanf("%lld ",&v);
        x[v]++;
    }
        printf("%lld", x[1]);

}