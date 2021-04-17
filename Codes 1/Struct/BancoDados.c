#include <stdio.h>
#include <string.h>

typedef struct {
int Idade,Amigos,Fotos;
char Nome[52],Sexo,EC;
}Cadastro;

int main(){

    int N,a;
    scanf("%d",&N);
    Cadastro Pessoa[N];

    for(a=0;a<N;a++){
        scanf(" %d", &Pessoa[a].Idade);
        scanf(" %[^\n]", Pessoa[a].Nome);
        scanf(" %c", &Pessoa[a].Sexo);
        scanf(" %c", &Pessoa[a].EC);
        scanf(" %d", &Pessoa[a].Amigos);
        scanf(" %d", &Pessoa[a].Fotos);
    }
    for(a=0;a<N;a++){
        printf("Idade: %d\n", Pessoa[a].Idade);
        printf("Nome: %s\n", Pessoa[a].Nome);
        printf("Sexo: %c\n", Pessoa[a].Sexo);
        printf("Estado Civil: %c\n", Pessoa[a].EC);
        printf("Numero de amigos: %d\n", Pessoa[a].Amigos);
        printf("Numero de fotos: %d\n", Pessoa[a].Fotos);
        printf("\n");
    }

    return 0;
}

