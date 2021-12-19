#include <stdio.h>

int main(){

    long long int k,b,a,cont=0;
    while(scanf("%lld %lld",&k,&b)!=EOF){
        while(k!=0){
            a=k%b;k/=b;cont+=a;
        }
        printf("%d\n",cont);
        cont=0;
    }

    return 0;
}