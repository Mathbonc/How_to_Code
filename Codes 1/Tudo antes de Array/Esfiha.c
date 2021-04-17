#include <stdio.h>
#include <math.h>

int main(){

    int A,B,C,D,E;
    scanf("%d\n%d\n%d %d\n%d",&A,&B,&C,&D,&E);

    if(C==0){//Cartão 5%
        if((A+B)>(D*E*0.05)){
            printf("Faz um Ifood!");
        }else printf("pede menos que as esfihas nao vao acabar hoje!");
    }else{//Verdinha/Débito 15%
        if((A+B)>(D*E*0.15)){
            printf("Faz um Ifood!");
        }else printf("pede menos que as esfihas nao vao acabar hoje!");
    }

    return 0;
} 