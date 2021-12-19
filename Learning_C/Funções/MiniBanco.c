#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[30],cpf[15];
    int saldo;
} Pessoa;


int main(){
    Pessoa *Cliente=NULL;
    Cliente = (Pessoa *) malloc(1 * sizeof(Pessoa));
    int i,Num=0;
    
    while(scanf("%d",&Cliente[Num].saldo) && Cliente[Num].saldo>0){
        Cliente = (Pessoa *) realloc(Cliente,(Num+1) * sizeof(Pessoa));
        if(Cliente==NULL){
            printf("Não foi possível alocar.");
            exit(1);
        }
        printf("Digite seu nome:\n");
        scanf(" %[^\n]",Cliente[Num].nome);
        printf("Digite seu CPF:\n");
        scanf(" %s",Cliente[Num].cpf);
        printf("Saldo Salvo!\n"
                "Digite um novo Saldo:");
        Num++;
    }
    printf("Nomes Salvos:\n");
    for(i=0;i<Num;i++){
        
        printf("%s\n",Cliente[i].nome);
    }
    free(Cliente);
    return 0;
}