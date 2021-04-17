#include <stdio.h>
#include <string.h>

int main(){

    int i=0,j,aux1,aux[12];
    char String[25][5]; //Colunas: N de movimentos possíveis // Linhas: Tamanhos

    //Entrada
    while(scanf(" %s", String[i])!=EOF){
        i++;
    }
    
    for(i;i>0;i--){
        aux1=strlen(String[i]);
        if(aux1==1){
            printf("%s ",strcat(String[i],"'"));
        }else if(String[i][1]==39){
            printf("%c ",String[i][0]);
        }else{
            printf("%s ",String[i]);
        }
    }

    

    return 0;
}

