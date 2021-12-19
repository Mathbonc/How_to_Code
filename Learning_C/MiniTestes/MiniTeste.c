#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    float Valor;
    int NColuna;
}Coluna;

typedef struct{
    int NLinha,qntdCols;
    Coluna *Pilar;
}Linha;


Linha *preencheMatriz(int *qtdLinhas);
int encontraLinha(Linha *matriz, int qtdLinhas, int Nlinha);
int encontraColuna(Linha *matriz, int qtdLinhas, int Nlinha, int NColuna);
void ordenaMatriz(Linha *matriz, int qtdLinhas);
void printMatriz(Linha *matriz, int qtdLinhas);

int main(){
    int qtdLinhas=0,i;
    Linha *Tenue=NULL;
    Tenue = preencheMatriz(&qtdLinhas);
    ordenaMatriz(Tenue,qtdLinhas);
    printMatriz(Tenue,qtdLinhas);
    //DESALOCANDO//
    for(i=0;i<qtdLinhas;i++){
        free(Tenue[i].Pilar);
    }
    free(Tenue);
    return 0;
}

Linha *preencheMatriz(int *qtdLinhas){
    char Escolha;
    int linha,coluna,EL,EC,i; //EL: Salvar Retorno da função encontrarLinha//EC: encontrarColuna//
    float valor;
    Linha *Fio=NULL;
    //ALOCANDO O PRIMEIRO ESPAÇO//
    Fio = (Linha *) calloc(1,sizeof(Linha));
    if(Fio!=NULL){
        Fio[0].Pilar = (Coluna *) calloc(1,sizeof(Coluna));
        if(Fio[0].Pilar!=NULL){
            //RESTO DA FUNÇÃO//
            printf("Digite qualquer letra para armazenar ou 'N' para continuar\n");
            while(scanf("%c",&Escolha),Escolha!='N',Escolha!='n'){
                printf("Digite os valores na seguinte ordem: 'Linha' 'Coluna' 'Valor'\n");
                scanf("%d %d %d", &linha, &coluna, &valor);
                if(linha!=0 && coluna!=0 && valor!=0){ //ARMAZENAR 
                    if(encontraLinha(Fio,*qtdLinhas,linha)!=-1){//VERIFICAR SE EXISTEM LINHAS OU COLUNAS 
                        EL=encontraLinha(Fio,*qtdLinhas,linha);
                        if(encontraColuna(Fio,*qtdLinhas,linha,coluna)!=-1){//VERIFICAR SE EXISTEM COLUNAS
                            EC=encontraColuna(Fio,*qtdLinhas,linha,coluna);
                            Fio[EL].Pilar[EC].Valor=valor;
                        }
                        else{//NOVA COLUNA
                            Fio[EL].Pilar = (Coluna *) realloc(Fio[EL].Pilar,sizeof(Coluna*)*(Fio[EL].qntdCols+1));
                            if(Fio[EL].Pilar != NULL){
                                Fio[EL].qntdCols+=1;
                                Fio[EL].Pilar[Fio[EL].qntdCols-1].Valor=valor;
                            }
                            else{
                                printf("Nao foi possivel alocar 1.\n");
                            }   
                        }
                    }
                    else{//NOVA LINHA NOVA COLUNA
                        Fio = (Linha *) realloc(Fio,sizeof(Linha)*((*qtdLinhas)+1));
                        if(Fio != NULL){
                            *qtdLinhas+=1;
                            Fio[(*qtdLinhas)-1].Pilar = (Coluna *) realloc(Fio[(*qtdLinhas)-1].Pilar,sizeof(Coluna *)*(Fio[(*qtdLinhas)-1].qntdCols)+1); //Alocando Pilares pra essa nova Linha
                            if(Fio[(*qtdLinhas)-1].Pilar != NULL){
                                Fio[(*qtdLinhas)-1].qntdCols+=1;
                                //Colocando NLinha e NColuna//
                                Fio[(*qtdLinhas)-1].NLinha=linha;
                                Fio[(*qtdLinhas)-1].Pilar[Fio[(*qtdLinhas)-1].qntdCols-1].NColuna=coluna;
                                //Colocando Valor//
                                Fio[(*qtdLinhas)-1].Pilar[Fio[(*qtdLinhas)-1].qntdCols-1].Valor=valor;
                            }
                            else {
                                printf("Nao foi possivel alocar 2.\n");
                                *qtdLinhas-=1;
                            }
                        }
                        else{
                            printf("Nao foi possivel alocar 3.\n");
                        }   
                    }
                }
                else{
                    printf("Comando Invalido.\n");
                }
                printf("Digite qualquer letra para armazenar ou 'N' para continuar\n");
                scanf("%c",&Escolha);
            }
        }
        else{
            printf("Nao foi possivel alocar");
            exit(1);
        }
    }else{
        printf("Nao foi possivel alocar");
        exit(1);
    }
    return Fio;
    //DESALOCANDO//
    for(i=0;i<*qtdLinhas;i++){
        free(Fio[i].Pilar);
    }
    free(Fio);
}

int encontraLinha(Linha *matriz, int qtdLinhas, int Numlinha){
    int i,aux=0,aux2;
    for(i=0;i<qtdLinhas;i++){
        if(matriz[i].NLinha==Numlinha){
            aux++;aux2=i;
        }
        
    }
    if(aux==1){
        return aux2;
    }else{
        return -1;
    }
}

int encontraColuna(Linha *matriz, int qtdLinhas, int Numlinha, int NumColuna){
    int i,j,aux=0,aux2,k=encontraLinha(matriz,qtdLinhas,Numlinha);
    if(k!=-1){
        for(i=0;i<matriz[k].qntdCols;i++){
            if(matriz[k].Pilar[i].NColuna==NumColuna){
                aux++;aux2=i;
            }
        }
        if(aux==1){
            return aux2;
        }else{
            return -1;
        }
    }
}

void ordenaMatriz(Linha *matriz, int qtdLinhas){
    int i,j,k;
    Linha MatrizAUX;
    Coluna ColunaAUX;
    //ORDENANDO LINHAS//
    for(i=0;i<qtdLinhas-1;i++){
        for(j=i+1;j<qtdLinhas;j++){    
            if(matriz[i].NLinha>matriz[j].NLinha){
                MatrizAUX = matriz[i];
                matriz[i] = matriz[j];
                matriz[j] = MatrizAUX;
            }
        }
    }
    //ORDENANDO COLUNAS//
    for(i=0;i<qtdLinhas;i++){
        for(j=0;j<matriz[i].qntdCols-1;j++){
            for(k=j+1;k<matriz[i].qntdCols;k++){
                if(matriz[i].Pilar[j].NColuna>matriz[i].Pilar[k].NColuna){
                    ColunaAUX = matriz[i].Pilar[j];
                    matriz[i].Pilar[j] = matriz[i].Pilar[k];
                    matriz[i].Pilar[k] = ColunaAUX;
                }
            }
        }
    }
}

void printMatriz(Linha *matriz, int qtdLinhas){
    int i,j,a,b,IndiceColuna=0,IndiceLinha=0;
    for(i=0;i<qtdLinhas;i++){
        if(matriz[i].NLinha>IndiceLinha){
            IndiceLinha=matriz[i].qntdCols;//ACHANDO O MAIOR VALOR DE LINHA
        }
    }
    for(i=0;i<qtdLinhas;i++){
        for(j=0;j<matriz[i].qntdCols;j++){   
            if(matriz[i].Pilar[j].NColuna>IndiceColuna){
                IndiceColuna=matriz[i].Pilar[j].NColuna;//ACHANDO O MAIOR VALOR DE COLUNA 
            }
        }
    }
    
    for(a=0;a<qtdLinhas;a++){
        for(b=0;b<matriz[a].qntdCols;b++){
            for(i=0;i<IndiceLinha;i++){  
                if(i==matriz[a].NLinha){    
                    for(j=1;j<IndiceColuna;j++){ //PRINTANDO AS COLUNAS//
                        if(j==matriz[a].Pilar[b].NColuna){
                            printf("%f ",matriz[a].Pilar[b].Valor);
                        }
                        else{
                            printf("0 ");
                        }
                    }
                    printf("\n");
                }
                else{
                    for(j=0;j<matriz[a].qntdCols;j++){
                        printf("0 ");
                    }
                    printf("\n");
                }
            }
        }
    }   
        
}