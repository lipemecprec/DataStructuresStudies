// EXPECT - Life, the Universe, and Everything (Interactive)
// https://www.spoj.com/problems/EXPECT/

#include <stdio.h>
int main(){
  int n = 0;
  while (n != 42){
    scanf("%d",&n);
    printf("%d\n",n);
    fflush(stdout);
  }
  return 0;
}