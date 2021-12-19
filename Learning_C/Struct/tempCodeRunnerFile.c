#include <stdio.h>
#include <string.h>

typedef struct {
int Numero,Poltrona;
char Data[12],Hora[6],Origem[101],Destino [101];
}Dados;

typedef struct {
    int Idade;
    char Nome[101];
    Dados Passagem;
}Pessoa;

int main(){

    Pessoa Passageiro[44];
    int a=0,i,n=0,SomId=0,Media;

    while(scanf("%d",&Passageiro[a].Passagem.Numero),Passageiro[a].Passagem.Numero!=-1){
        scanf(" %s", Passageiro[a].Passagem.Data);
        scanf(" %[^\n]", Passageiro[a].Passagem.Origem);
        scanf(" %[^\n]", Passageiro[a].Passagem.Destino);
        scanf(" %s", Passageiro[a].Passagem.Hora);
        scanf("%d", &Passageiro[a].Passagem.Poltrona);
        scanf("%d", &Passageiro[a].Idade);
        scanf(" %[^\n]", &Passageiro[a].Nome);
        a++;n++;
    }
    for(i=0,a=0;i<n-1;i++,a++){
        SomId+=Passageiro[a].Idade;
        Media=SomId/i;
    }
    for(i=0,a=0;i<n-1;i++,a++){
        if(Passageiro[a].Idade>Media && Passageiro[a].Passagem.Poltrona%2==0){
            printf(" %s\n", Passageiro[a].Nome);
        }
    }

    return 0;
}