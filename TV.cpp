#include <stdio.h>

int M = 1, N = 1;
int img[1024][1024] , swap = 0, Teste = 0;

int main(){
    
    while (M != 0 || N != 0){
        Teste++;
        int X = 1, Y = 1, Xsum = 0, Ysum = 0;
        scanf("%d %d ", &M, &N); // M = rows | N = collumns ENTRY
        
        for (int i = 0 ; i < M ; i++ ){ // Image ENTRY
            for ( int j = 0 ; j < N ; j++){
                scanf ("%d ", &img[i][j]);
            }
        }
        
        if(M != 0 || N != 0) {
            
            while (X != 0 || Y != 0){    // Corrections ENTRY
                scanf("%d %d ", &X, &Y);
                Xsum = Xsum + X;
                Ysum = Ysum + Y;
            }

            if(Xsum != 0){
                if(N>0) Xsum = Xsum % N;
                if(Xsum<0)Xsum = N + Xsum;
    
                for (int k = 0 ; k < Xsum ; k++){ // Corrections to be made in X direction
                    for (int i = 0 ; i < M ; i++ ){ // from top to bottom
                        for ( int j = N - 1 ; j > 0  ; j--){ // from right to left
                            swap = img[i][j];
                            img[i][j] = img[i][j-1];
                            img[i][j-1] = swap;
                        }
                    } 
                }
            }
            
            if(Ysum != 0){
                if(M>0) Ysum = Ysum % M; // To reduce correctios to range
                if(Ysum<0)Ysum = M + Ysum;
                Ysum = M - Ysum;
                for (int k = 0 ; k < Ysum ; k++){ // Corrections to be made in Y direction
                    for (int i = M - 1  ; i > 0 ; i-- ){ // from bottom to top
                        for ( int j = 0 ; j < N  ; j++){ // from left to right
                            swap = img[i][j];
                            img[i][j] = img[i-1][j];
                            img[i-1][j] = swap;
                           // printf ("%d | ", img[i][j]);
                        }
                    } 
                }
            }
            
            printf ("Teste %d\n",Teste);
            for (int i = 0 ; i < M ; i++ ){
                for ( int j = 0 ; j < N ; j++){
                    printf ("%d ",img[i][j]);
                }
                printf("\n");
            }
            printf ("\n");
        }
    }
}