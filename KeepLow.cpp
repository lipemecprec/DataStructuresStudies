#include <iostream>
#include <string>

char keepLow (char letter) {
    if (letter >= 65 && letter <= 90) letter = letter+32; //if uppercase transform to lowercase
    // printf ("%c",letter);
    return letter;
};

bool isNotVowel (char letter) {
    char vowelsLowerCase[6] = {'a','o','y','e','u','i'};
    for (int i = 0; i <= 5 ; i++ ){
        // printf ("(Vowel test i = %d letter = %c > %c \n",i , letter , vowelsLowerCase[i]);
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
        // printf ("(B4 test i = %d letter = %c > %c \n",i , str[i] , isNotVowel(str[i]) ? "T":"F");
        if (isNotVowel(str[i])){
            
           // printf ("(i = %d letter = %c \n",i,str[i]);
            printf (".%c",str[i]);
        }
    };
}