#include <stdio.h>

int main(){

    int a,b,c,d, x1,x2; //c e d são lados do retângulo
    scanf("%d %d \n %d %d", &a,&b,&c,&d);
    

    if(a<b){
        x1=a;
        a=b;
        b=x1;
    }if(c<d){
        x2=c;
        c=d;
        d=x2;
    }

    if(a<c || b<d){
        printf("Procura outro lugar, bilu");
    }else{
        printf("Pousa, bilu");
    }
    return 0;
}