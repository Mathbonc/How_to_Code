#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char Regulagem[20];
    int NRegulagem;
}Regulagem;


char **carregaRegulagensDeFilial(int filial, int *tamVet);
Regulagem *acumulaRegulagensComuns(Regulagem *regulagensComuns, int tamComuns, char **regulagensFilial, int tamRegsFilial);
void *ordenaRegulagensPorFrequencia(Regulagem *regulagensComuns, int tamComuns);
void salvaRegulagens(Regulagem *regulagensComuns, int tamRegs);


int main(){
    char **RegulagensFilial=NULL;
    Regulagem *Padroes=NULL;
    int F,tamV=0,i,j;
    int tamReg=0;
    scanf("%d",&F);
    if(101<=F && F<=199){
        for(i=101;i<F;i++){
            RegulagensFilial = carregaRegulagensDeFilial(i,&tamV);
            Padroes = acumulaRegulagensComuns(Padroes,0,RegulagensFilial,tamV);
            for(i=0;i<tamV;i++){
                free(RegulagensFilial[i]);
            }
            free(RegulagensFilial);
            tamReg++;
        }   
    }
    ordenaRegulagensPorFrequencia(Padroes,tamReg);
    salvaRegulagens(Padroes,tamReg);
    free(Padroes);
}

char **carregaRegulagensDeFilial(int F, int *tamVet){
    FILE *Arq;
    char FilialS[4],**RFTemp,Regulagem[8],StringTEMP[257],*StringTEMP2;
    int i=0;
    itoa(F,FilialS,10);
    Arq = fopen("FilialS.txt","rt");
    if(Arq==NULL){
        printf("Problema na Abertura");
        exit(1);
    }
    while(foef(Arq)){
        fread(StringTEMP,sizeof(char),1,Arq);
        StringTEMP2 = strchr(StringTEMP,'[');
        memcpy(Regulagem,StringTEMP2,7);
        RFTemp = (char**) realloc (RFTemp,sizeof(char*)*(i+1));
        RFTemp[i] = (char*) realloc (RFTemp,sizeof(char)*8);
        strcpy(RFTemp[i],Regulagem);
        i++;
    }
    (*tamVet)++;
    fclose(Arq);
    return RFTemp;
}
Regulagem *acumulaRegulagensComuns(Regulagem *regulagensComuns, int tamComuns, char **regulagensFilial, int tamRegsFilial){
    int i,j;
    regulagensComuns = (Regulagem *) calloc(1,sizeof(Regulagem));
    for(i=0;i<tamComuns;i++){
        for(j=0;j<tamRegsFilial;j++){  
            if(strcmp(regulagensComuns[i].Regulagem,"/0")!=0){    
                if(strcmp(regulagensComuns[i].Regulagem,regulagensFilial[j])==0){
                    regulagensComuns[i].NRegulagem++;
                }
            }
            else{
                strcpy(regulagensComuns[i].Regulagem,regulagensFilial[j]);
                regulagensComuns[i].NRegulagem=1;
            }
        }
    }
}
void *ordenaRegulagensPorFrequencia(Regulagem *regulagensComuns, int tamRegs){
    int i,j;
    Regulagem Aux;
    for(i=0;i<tamRegs-1;i++){
        for(j=i+1;j<tamRegs;j++){
            if(regulagensComuns[i].NRegulagem<regulagensComuns[j].NRegulagem){
                Aux = regulagensComuns[i];
                regulagensComuns[i] = regulagensComuns[j];
                regulagensComuns[j] = Aux;
            }
        }
    }
}
void salvaRegulagens(Regulagem *regulagensComuns, int tamRegs){
    FILE *FreqRegs;
    FreqRegs = fopen("FregRgs.bin","wb");
    if(FreqRegs!=NULL){
        fwrite(regulagensComuns,sizeof(Regulagem),tamRegs,FreqRegs);
        fclose(FreqRegs);
    }
    else{
        printf("Não foi possível arquivar");
        exit(2);
    }
}