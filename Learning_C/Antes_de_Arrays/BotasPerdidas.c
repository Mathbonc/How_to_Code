#include <stdio.h>
#include <math.h>

int main(){
    int Nbot,i,aux=0;
    scanf("%d",&Nbot);
    while(Nbot!=-1){
        int Tamanho,Botas[61][2]={0};
        char Lado;
        for(i=0;i<Nbot;i++){
            scanf("%d %c",&Tamanho, &Lado);
            if(Lado=='E'){
                Botas[Tamanho][0]++;
            }else{
                Botas[Tamanho][1]++;
            }
        }
        for(i=0;i<60;i++){
            if(Botas[i][0]<Botas[i][1]){aux+=Botas[i][0];}
            else aux+=Botas[i][1];
        }printf("%d\n",aux);aux=0;
        scanf("%d",&Nbot);
    }
    return 0;
}