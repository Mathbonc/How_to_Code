#include <stdio.h>
#include <string.h>


typedef struct {
    char nome[100],sexo;
    int idade;
}Pessoa;

typedef struct{
    int cont;
    Pessoa Alguem[4];
}Imovel;

typedef struct{
    Imovel Apartamento[10][2]; 
}Endereco;



int main(){
    //Variaveis Gerais//
    Endereco Predio[3];
    Imovel Casa[10];
    int i,j,k,casa,pre,SexoAux,AP,AND,saida=0,S;
    char aux[20];
    //Variaveis Para os Ciclos//
    int c,an,ap,p;
    int SomIdade=0,contIdade=0;
    int ContM=0,ContF=0;
    //Zerando//
    Casa->cont=0;
    for(i=0;i<10;i++){
        for(j=0;j<2;j++){
            Predio->Apartamento[i][j].cont=0;
        }
    }
    //Ciclo dos APS//
    for(c=0;c<3;c++){
        for(an=0;an<10;an++){
            for(ap=0;ap<2;ap++){
                for(p=0;p<4;p++){
                    Predio[c].Apartamento[an][ap].Alguem[p].idade=0;
                    Predio[c].Apartamento[an][ap].Alguem[p].sexo=='\0';
                    
                }
            }
        }
    }
    //Ciclo das Casas
    for(c=0;c<30;c++){
        for(p=0;p<4;p++){
            Casa[c].Alguem[p].idade=0;
            Casa[c].Alguem[p].sexo=='\0';
        }
    }
    //===Entrada===//
    printf("Ola, seja-vindx a Calculadora da Media das Idades dos Moradores de uma Rua %-10c(CMIMR)\n", ' ');
    while(saida!=1){
        printf("Informe se voce mora em uma Casa ou Apartamento: %-10c (Digite 'Casa' ou 'Apartamento')\n",' ');
        scanf(" %s",aux);
        if(strcmp(aux,"Casa")==0){
            printf("Digite o numero da sua casa:");
            scanf("%d",&casa);
            if(casa<0 || casa>29){
                printf("Casa invalida.\n");
            }else{
                if(Casa[casa].cont<4){
                    printf("Digite seu nome: ");
                        scanf(" %s", Casa[casa].Alguem[Casa[casa].cont].nome);
                        Casa[casa].cont++;
                    printf("Digite sua idade: ");
                        scanf("%d", &Casa[casa].Alguem[Casa[casa].cont].idade);
                    printf("Digite seu sexo:%-10c (M ou F)\n",' ');
                        scanf(" %c",&SexoAux);
                    if(SexoAux=='M'||SexoAux=='F'){
                        Casa[casa].Alguem[Casa[casa].cont].sexo=SexoAux;
                    }else{
                        printf("Tem tantos Hoje...\n");
                    }
                }else{
                    printf("Essa casa ja ta cheia!\n");
                }
                
            }
        }
        else if(strcmp(aux,"Apartamento")){
            printf("Digite o número do prédio:");
            scanf("%d", &pre);
            if(pre<0 || pre>2){
                printf("Prédio Inválido.\n");
            }else{
                printf("Digite seu Andar: ");
                scanf("%d",&AND);
                if(AND<0||AND>9){
                    printf("Andar Inválido.\n");
                }else {
                    printf("Digite seu Apartamento: ");
                    scanf("%d",&AP);
                    if(AP<0||AP>1){
                        printf("Apartamento Inválido.\n");
                    }else{
                        if(Predio[pre].Apartamento[AND][AP].cont<4){
                            printf("Digite seu nome: ");
                            scanf(" %s", Predio[pre].Apartamento[AND][AP].Alguem[Predio[pre].Apartamento[AND][AP].cont].nome);
                            printf("Digite sua idade: ");
                            scanf("%d", &Predio[pre].Apartamento[AND][AP].Alguem[Predio[pre].Apartamento[AND][AP].cont].idade);
                            printf("Digite seu sexo:%-10c (M ou F)\n",' ');
                            scanf(" %c", &SexoAux);
                            if(SexoAux=='M' || SexoAux=='F'){
                                Predio[pre].Apartamento[AND][AP].Alguem[Predio[pre].Apartamento[AND][AP].cont].sexo=SexoAux;
                            }else{
                                printf("Tem tantos hoje...\n");
                            }
                        }
                        else{
                            printf("Não tem mais lugares aqui...\n");
                        }
                    }
                }
            }
                
            

        }else printf("Comando Inválido.");
        printf("Deseja encerrar a leitura?%-10c(S/N)\n",' ');
        scanf(" %c", &S);
        if(S=='S'){
            saida=1;
        }
    }
    //===Contagem===//
    //Ciclo das Casas//
    for(c=0;c<30;c++){
        for(p=0;p<4;p++){
            SomIdade+=Casa[c].Alguem[p].idade;
            contIdade++;
            if(Casa[c].Alguem[p].sexo=='M'){
                ContM++;
            }else{
                ContF++;
            }
        }
    }
    //Ciclo dos APS//
    for(c=0;c<3;c++){
        for(an=0;an<10;an++){
            for(ap=0;ap<2;ap++){
                for(p=0;p<4;p++){
                    SomIdade+=Predio[c].Apartamento[an][ap].Alguem[p].idade;
                    contIdade++;
                    if(Predio[c].Apartamento[an][ap].Alguem[p].sexo=='M'){
                        ContM++;
                    }else{
                        ContF++;
                    }
                }
            }
        }
    }
    //===Calculos===//
    float Media,Percentual;
    Media=SomIdade/contIdade;
    Percentual=ContM/ContF;
    //===Saída===//
    printf("A Media de Idade dessa rua e: %f\n E o numero de homens e de %f para cada mulher\n",Media,Percentual);
    printf("Tenha um bom dia :)");
    return 0;
}