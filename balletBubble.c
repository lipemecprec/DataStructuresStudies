#include <iostream>

using namespace std;

int main() {

    int N = 0, swap = 0, pares = 0, oldest = 0;
    int v[100010];
    
    // get values
    scanf("%d ",&N);
    
    for(int i = 0; i<N ; i++)scanf("%d ", &v[i]);
    
    // Bubble sort
    int i = 0;
    for(int j = 0 ; j < N - 1; j++){
        for(i = 0 ; i < N - j - 1; i++){
            if(v[i]>v[i+1]){
                if(v[i]>=oldest){
                    pares++;
                    oldest=v[i];
                // printf("\nOLD: %d \t PARES: %D\t I:%d \t J: %d\t", oldest, pares, i, j);
                }
                swap = v[i];
                v[i] = v[i+1];
                v[i+1] = swap;
                // for(int k = 0; k<N ; k++)printf("%d ", v[k]);
            }            
        }
        oldest = 0;
    }
    
    printf("%d", pares);

}