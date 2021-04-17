#include <stdio.h>

int main(){

    int a,b,c,K,C,R; //K e C variáveis auxiliares | R resposta
    char x,y; // 94 -> "^" / 118 -> "v"
    scanf("%d %c %d %c %d",&a,&x,&b,&y,&c);

    if(x<y){//Prioridade pro Primeiro
        if(a==1 && b==1){
            R=1;
        }else if(c==1){
            R=1;
        }else R=0;
    }else if(x>y){//Prioridade pro Segundo
        if(b==1 && c==1){
            R=1;
        }else if(a==1){
            R=1;
        }else R=0;
    }else if(x==y){//X e Y iguais
        if(x==94){//Apenas "e"
            if(a==1 && b==1 && c==1){
            R=1;
            }else R=0;
        }else if(a==1 || b==1 || c==1){//Apenas "ou"
            R=1;
        }else R=0;
    }
    printf("%d",R);
    return 0;
}