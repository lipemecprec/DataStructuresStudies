#include <stdio.h>
#include <string.h>

char keepLow (char letter) {
    if (letter >= 65 && letter <= 90) letter = letter+32; //if uppercase transform to lowercase
    return letter;
};

bool isNotVowel (char letter) {
    char vowelsLowerCase[6] = {'a','o','y','e','u','i'};
    for (int i = 0; i <= 5 ; i++ ){
        if (letter == vowelsLowerCase[i]) return false;
    }
    return true;
}

int main() {
    
    char str[110];
    scanf("%[^\n]", &str);
    
    int strSize = strlen(str);
    for (int i=0; i < strSize; i++){
        str[i] = keepLow(str[i]);
        if (isNotVowel(str[i])){
            printf (".%c",str[i]);
        }
    };
}


________________________________________________________________


#include <iostream>

using namespace std;

int main() {
    int mineSpace, isBomb;

    scanf("%d",&mineSpace);
    
    int mineRadar[51]={};
    
    for (int i = 0 ; i < mineSpace ; i++){

        scanf("%d",&isBomb);
        if (isBomb == 1){
            mineRadar[i+1]++; // Next cell
            mineRadar[i]++; // This cell
            mineRadar[i-1]++; // Previous cell
        }
        // printf("isBomb:  %d | mineSpaceb4 %d | mineSpaceAfter %d | radarOverview: %d %d %d %d %d %d \n", isBomb, mineRadar[i-1], mineRadar[i+1], mineRadar[0], mineRadar[1], mineRadar[2], mineRadar[3], mineRadar[4], mineRadar[5]);
        
    };
    
    for (int i = 0 ; i < mineSpace ; i++){

        printf("%d\n", mineRadar[i]);
        
    };
     
}


________________________________________________________________


#include <stdio.h>
#include <stdbool.h>

int main() {
    int N = 1;
    int collection[1010] = {};
    
    scanf("%d ", &N);

    for (int i = 0 ; i < N + 1; i++){
        scanf(" %d ", &collection[i]);
    }
    
    int sorted = 0, swapTemp;
    while(sorted == 0){
        int swaped = 0;
        for (int i = 0 ; i < N - 1 ; i++){
            if (collection[i] > collection[i+1]){
                swapTemp = collection[i];
                collection[i] = collection[i+1];
                collection[i+1] = swapTemp;
                swaped = 1;
            }
        }
        if (swaped == 0){
           sorted = 1;     
        }
    }
    
    collection[N] = N + 1;
    for (int i = 0 ; i < N + 1; i++){
        if (collection[i] == collection[i+1]-2){
            printf("%d", collection[i]+1);
            i = N;
        }
    }
}



________________________________________________________________

MATRIX - NÃO ESTÁ FUNCIONANDO...

#include <stdio.h>
#include <string.h>

int checkBalance (char s[] , int n){
    int zeros = 0, ones = 0;
    
    for (int i = 0 ; i < n ; i++){
        // printf("%c", s[i]);
        if ( s[i]==0 ) zeros++ ;
        if ( s[i]==1 ) ones++ ;
    }
    return (zeros==ones);
}

int main() {
    int n;
    
    scanf("%d ", &n);
    
    char s[110] = {};
    for (int i = 0 ; i < n ; i++){
        scanf("%c", &s[i]);
    }
    
    int splits = 1;
    int splitSize = 0;
    
    if(!checkBalance(s,n)){
        printf("%d\n%s",splits, s);   
    }else{
        splits++;
        char firstHalf[] = {}, secondHalf[] = {};
        int fHsize = 0, sHsize = 0;
        fHsize++;
        int j = 0;
        for (int i = 0 ; i < n ; i++){
            if(i < fHsize) {
                firstHalf[i] = s[i];
            }else{
                secondHalf[j] = s[i]; 
                j++;
            }
            printf("1st %s\n", firstHalf);
            printf("2nd %s\n", secondHalf);
        }
    }
}

________________________________________________________________

TV - So far so good

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