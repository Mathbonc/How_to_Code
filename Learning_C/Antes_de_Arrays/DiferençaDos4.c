#include <stdio.h>
#include <math.h>

int main(){

   int e,n,s1,s2;

    do{
      scanf(" %d", &e);
      if(e!=0){
        n=(e-1)/2;
        s1=(n+1)*(n+1);
        s2=pow(n,2);
        printf("%d-%d\n", s1,s2);
      }
    }while (e!=0);
    

   return 0;
}