#include <stdio.h>

int main(){

    int x,y;
    scanf("%d \n %d", &x, &y);

    if(x==0 || y==0){
        if(x==0 && y!=0){
            printf("Sobre o eixo y");
        }else if (x!=0 && y==0){
            printf("Sobre o eixo x");
        }else printf ("Sobre a Origem");
    }else if(x>0){
        if(y>0){
            printf("Primeiro Quadrante");
        }else printf("Quarto Quadrante");
    }else if(x<0){
        if(y>0){
            printf("Segundo Quadrante");
        }else printf("Terceiro Quadrante");

    }

    return 0;
}