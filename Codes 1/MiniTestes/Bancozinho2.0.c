#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[20],cpf[15];
    int saldo;
} Pessoa;



void Cadastrar(Pessoa **Cliente,int *numerocliente);
int Procurar(Pessoa *Cliente,int numerocliente);
void Excluir(Pessoa **Cliente,int *numerocliente);
void Deposita(Pessoa **Cliente,int *numerocliente);
void AbrirArquivo(Pessoa **Cliente,int *numerocliente);
void Armazenar(Pessoa *Cliente,int numerocliente);

int main(){
    Pessoa *Cliente=NULL;
    Cliente = (Pessoa *) calloc(1,sizeof(Pessoa));
    if(Cliente!=NULL){
        int Escolha;
        int n=0;
        AbrirArquivo(&Cliente,&n);
        while(Escolha!=5){  
            printf("Ola, Seja bem-vindo ao Banco Simulator!\n");
            printf("Digite 1 para: Cadastrar.\n"
                "Digite 2 para: Procurar Cliente.\n"
                "Digite 3 para: Excluir Cadastro.\n"
                "Digite 4 para: Depositar.\n"
                "Digite 5 para Sair\n");
            scanf("%d",&Escolha);
            if(Escolha==1){
                Cadastrar (&Cliente , &n);
            }else if(Escolha==2){
                Procurar (Cliente, n);
            }else if(Escolha==3){
                Excluir (&Cliente, &n);
            }else if(Escolha==4){
                Depositar (&Cliente, &n);
            }else if(Escolha==5){
            }else{
                printf("Comando Invalido");
            }
            
        }
        Armazenar(Cliente,n);
        free(Cliente);
    }
}

void Cadastrar (Pessoa **Cliente,int *n){
    float Saldo;
    char Nome[20];
    
    printf("Digite seu Saldo:\n");
    scanf("%f",&Saldo);
    if(Saldo>0){
        *Cliente = (Pessoa *) realloc(*Cliente,sizeof(Pessoa)*((*n)+1));
        printf("Digite seu nome:\n");
        scanf(" %[^\n]", *Cliente[*n]->nome);
        if(Procurar(Cliente,n)!=-1){
            printf("Digite seu CPF:\n");
            scanf(" %[^\n]", *Cliente[*n]->cpf);
            printf("Cadastrado!\n");
            *n+=1;
        }else{
            print("Essa pessoa já foi cadastrada!\n");
        }
    }
}
int Procurar (Pessoa *Cliente,int n){
    int i,aux=-1;
    char Procurar[20];
    printf("Digite o nome do Cliente:\n");
    scanf(" %[^\n]",Procurar);
    for(i=0;i<n;i++){
        if(strcmp(Procurar,Cliente[i].nome)==0){
            aux=i;
        }
    }
    if(aux>=0){
        return aux;
    }else {
        return -1;
    }
}
void Excluir (Pessoa **Cliente,int *n){
    int i,aux=-1;
    char SN;
    aux = Procurar(Cliente,n);
    if(aux>=0){
        printf("Tem certeza que deseja excluir esse cadastro?\n"
                "%s\n",Cliente[aux]->nome);
        printf("Digite 'S' ou 'N':\n");
        scanf(" %c", &SN);
        if(SN!="S" && SN!="N"){
            printf("Comando Invalido.\n");
        }else if(SN=="N"){

        }else {
            Cliente[aux]=Cliente[*n-1];
            free(Cliente[*n-1]);
            *Cliente = (Pessoa*) realloc(Cliente,sizeof(Pessoa)*(*n-1));
            *n-=1;
        }
        
    }else{
        printf("Pessoa nao encontrada.\n");
    }
}
void Depositar(Pessoa **Cliente,int *n){
    int i,aux=-1;
    char SN;
    float Valor;
    aux = Procurar(Cliente,n);
    if(aux>=0){
        print("Tem certeza que deseja depositar na conta de:\n"
                "%s ?\n", Cliente[aux]->nome);
        printf("Digite 'S' ou 'N'\n");
        scanf(" %c",&SN);
        if(SN!="S" && SN!="N" && SN!="s" && SN!="n"){
            printf("Comando Invalido.\n");
        }else if(SN=="N" || SN=="n"){

        }else {
            printf("Digite o valor desejado:\n");
            scanf("%f", &Valor);
            if(Valor>0){
                Cliente[aux]->saldo+=Valor;
                printf("Depositado!\n");
            }else{
                printf("Apenas Depositamos >:(\n");
            }
        }
        
    }else{
        printf("Pessoa nao encontrada.\n");
    }
}
void Armazenar(Pessoa *Cliente,int n){
    FILE *Arq;
    int i;
    Arq = fopen("BancoDeDadosdoBanco.txt","wt");
    if(Arq!=NULL){
        fprintf(Arq,"%d\n",n);
        for(i=0;i<n;i++){
            fprintf(Arq,"%s | CPF: %s | Saldo: %d\n",Cliente[i].nome,Cliente[i].cpf,Cliente[i].saldo);
        }
        fclose(Arq);
    }
    else{
        printf("Nao foi possivel armazenar\n");
    }
}
void AbrirArquivo(Pessoa **Cliente, int *n){
    FILE *Arq;
    int i;
    Arq = fopen("BancoDeDadosdoBanco.txt","rt");
    if(Arq!=NULL){
        fscanf(Arq,"%d",n);
        *Cliente = (Pessoa *) calloc(n,sizeof(Pessoa));
        if(Cliente!=NULL){
            for(i=0;i<n;i++){
                fscanf(Arq," %s | CPF: %s | Saldo: %d\n",Cliente[i]->nome,Cliente[i]->cpf,Cliente[i]->saldo);
            }
        }
        fclose(Arq);
    }
    else{
       printf("Nao foi possivel abrir o arquivo.\n");
       exit(1);
    }
}