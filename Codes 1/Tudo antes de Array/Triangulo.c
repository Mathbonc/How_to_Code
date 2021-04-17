#include <stdio.h>

int main(){

    int a,b,c;
    scanf("%d %d %d", &a,&b,&c);
    
    if((a+b<=c)||(b+c<=a)||(c+a<=b)){
        printf("nao eh triangulo");
    }else{
        if(a==b && b==c){
            printf("eh equilatero");
        }else if((a!=b) && (b!=c) && (c!=a)){
            printf("eh escaleno");
        }else{
            printf("eh isosceles");
        }
    }
    return 0;
}