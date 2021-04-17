#include <stdio.h>

int main (){

    int n, x, c=0;//c->Contador | x-> auxiliar
    scanf("%d", &n);
    for(x=1;x<=n;x++){
        if(n%x==0){
            if(x%3==0){
                c++;
            }
        }
    }if(c==0){
        printf("O numero nao possui divisores multiplos de 3!");
    }else printf("%d\n", c);

    return 0;
}