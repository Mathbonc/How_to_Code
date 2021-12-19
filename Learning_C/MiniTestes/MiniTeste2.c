#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int id_pet,id_cliente;
    char nome_pet[100];
    char raca_pet[100];
    double altura,peso;
    int idade;
} pet;

typedef struct{
    int id;
    int qtd_pets;
    char nome[100];
    char endereco[100];
    pet *pets;
} clientes;

pet *leituraPets(int *qt_pets);
clientes *leituraClientes(int *qt_clientes);
void inserirPetsClientes(pet *vetorPets, clientes *vetorClientes, int qt_pets, int qt_clientes);
void ordenaClientes(pet *PETS,clientes *Pessoas,int n_pets,int n_clientes);
void consultaCliente(clientes *vetorClientes, int id, int qt_clientes);
void consultaPet(pet *vetorPets, int id, int qt_pets);

int main(){
    clientes *Pessoas;
    pet *PETS;
    int n_cliente=0,n_pets=0,id;
    PETS = leituraPets(&n_pets);
    Pessoas = leituraClientes(&n_cliente);
    inserirPetsClientes(PETS,Pessoas,n_pets,n_cliente);
    ordenaClientes(PETS,Pessoas,n_pets,n_cliente);
    printf("Clientes Armazenados:\n");
    for(id=0;id<n_cliente;id++){
        consultaCliente(Pessoas,id,n_cliente);
    }
}

pet *leituraPets(int *n_pets){
    FILE *ArqPET;
    pet *PETS2;
    long int tam;
    ArqPET = fopen("ArqPET","rb");
    if(ArqPET==NULL){
        return NULL;
    }
    fseek(ArqPET,0,SEEK_END);
    tam = ftell(ArqPET);
    rewind(ArqPET);
    tam/=sizeof(pet);
    (*n_pets)=tam;
    PETS2 = (pet *) calloc(tam,sizeof(pet));
    if(PETS2==NULL){
        printf("Não foi possível alocar. (1)");
        fclose(ArqPET);
        exit(1);
    }
    fread(PETS2,sizeof(pet),tam,ArqPET);
    return PETS2;
    fclose(ArqPET);
}
clientes *leituraClientes(int *n_cliente){
    int i,j;
    FILE *ArqCliente;
    clientes *ClienteTemp;
    long int tam;
    ArqCliente = fopen("ArqCliente","rb");
    if(ArqCliente == NULL){
        return NULL;
    }
    fseek(ArqCliente,0,SEEK_END);
    tam = ftell(ArqCliente);
    rewind(ArqCliente);
    tam/=sizeof(clientes);
    *n_cliente=tam;
    ClienteTemp = (clientes *) calloc(tam,sizeof(clientes));
    for(i=0;i<n_cliente;i++){
        ClienteTemp[i].pets = calloc(ClienteTemp[i].qtd_pets,sizeof(pet));
        if(ClienteTemp[i].pets==NULL){
            printf("Não foi possível alocar. (2)");
            fclose(ArqCliente);
            exit(2);
        }
    }
    if(ClienteTemp == NULL){
        printf("Não foi possível alocar. (3)");
        fclose(ArqCliente);
        exit(3);
    }
    fread(ArqCliente,sizeof(clientes),tam,ArqCliente);
    fclose(ArqCliente);
    return ArqCliente;
}
void inserirPetsClientes(pet *PETS, clientes *Pessoas, int n_pets, int n_clientes){
    int i,j;
    for(i=0;i<n_clientes;i++){
        for(j=0;j<n_pets;j++){
            if(PETS[j].id_cliente==Pessoas[i].id){
                Pessoas[i].pets[Pessoas[i].qtd_pets]=PETS[j];
                Pessoas[i].qtd_pets++;
            }
        }
    }
}
void ordenaClientes(pet *PETS,clientes *Pessoas,int n_pets,int n_clientes){
    int i,j,k;
    clientes TempC;
    pet TempP;
    //ORDENANDO CLIENTES//
    for(i=0;i<n_clientes-1;i++){
        for(j=i+1;j<n_clientes;j++){
            if(Pessoas[i].id>Pessoas[j].id){
                TempC=Pessoas[i];
                Pessoas[i]=Pessoas[j];
                Pessoas[j]=TempC;
            }
        }
    }
    //ORDENANDO PETS DENTRO DE CLIENTES//
    for(i=0;i<n_clientes;i++){
        for(j=0;j<Pessoas[i].qtd_pets-1;j++){
            for(k=j+1;j<Pessoas[i].qtd_pets;k++){
                if(Pessoas[i].pets[j].id_pet>Pessoas[i].pets[k].id_pet){
                    TempP = Pessoas[i].pets[j];
                    Pessoas[i].pets[j] = Pessoas[i].pets[k];
                    Pessoas[i].pets[k] =TempP;
                }
            }
        }
    }
}
void consultaCliente(clientes *Pessoas, int id, int n_clientes){
    int j;
    printf("Nome: %s\n",Pessoas[id].nome);
    printf("Endereco: %s\n",Pessoas[id].endereco);
    printf("Quantidade de Pets: %d\n",Pessoas[id].qtd_pets);
    printf("Pets:\n");
    for(j=0;j<Pessoas[id].qtd_pets;j++){
        consultaPet(Pessoas[id].pets,j,Pessoas[id].qtd_pets);
    }
        

}
void consultaPet(pet *PETS, int idp, int n_pets){
    printf("Nome: %s\n",PETS[idp].nome_pet);
    printf("Raca: %s\n",PETS[idp].raca_pet);
    printf("Idade: %d\n",PETS[idp].idade);
    printf("Altura: %lf\n", PETS[idp].altura);
    printf("Peso: %lf\n",PETS[idp].peso);
}