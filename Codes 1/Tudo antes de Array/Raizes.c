#include <stdio.h>
#include <math.h>
/*Aluno: Matheus Júlio
Cálculo de Raízes*/
int main(){
    
    float a ,b ,c ,Delta, Raiz1, Raiz2;

    printf("Digite os valores de Ax^2+Bx+C:");
    scanf("%f %f %f", &a ,&b ,&c);
    Delta = (b*b - 4*a*c);
    if(Delta >= 0){
        Raiz1 = (-b + sqrt(Delta))/(2*a);
        Raiz2 = (-b -sqrt(Delta))/(2*a);
        printf("As raizes sao: x1=%f e x2=%f", Raiz1, Raiz2);
    }
    else{
        printf("A equacao nao possui raizes reais.");
    }
    return 0;
}