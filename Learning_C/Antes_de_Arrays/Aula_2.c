#include <stdio.h>

int main (){
    float x,y;
    printf("Digite X e Y:");
    scanf("%f %f", &x, &y);
    printf("Inicio do if.\n");
    if(y != 0) {
        printf("Divsão = %f\n", x/y);
    }
    else {
        printf("Nao da pra dividir.\n");
    }
    printf("Final do if.");
    return 0;
}