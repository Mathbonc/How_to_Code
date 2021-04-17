#include <stdio.h>
#include <math.h>

int main(){

    long long int n,i,aux,aux2;
    int cont=0;

    scanf(" %lld",&n);
    while(n!=-1){
        aux=n;aux2=sqrt(n);
        for(i=2;i<aux2;i++){
            while(n%i==0){
                n/=i;cont++;
            }
        }if(n>1){cont++;}
        if(cont==4){printf("%lld eh um primo de 4\n",aux);}
        else printf("%lld, eu nunca duvidei\n",aux);
        cont=0;
        scanf(" %lld",&n);
    }

    return 0;
}