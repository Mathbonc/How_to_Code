#include <stdio.h>


int main(){

    int Linhas,Colunas,A[Linhas][Linhas+1],I[Linhas][Linhas+1],i,j,cond=0,aux1;
    printf("Número de Linhas:");
    scanf("%d", &Linhas);
    
    for(i=0;i<Linhas;i++){ //Determina os valores da matriz A
        for(j=0;i<=Linhas;j++){
            scanf("%d",&A[i][j]);
        }
    }
    
    for(i=j=0;i<Linhas && j<=Linhas;i++ && j++){
        
        if(A[i][j]==0){
            while(cond==0){//Se a11=0, Buscar em a1x,o um valor não nulo e trocar todos os elementos dessa Linha;(Elemento de Pivô)
                if(A[i][j]==0){
                    i++;
                }else{
                    for(j=0;j<=Linhas;j++){
                        I[i][j]=A[i][j];
                        A[i][j]=A[i][j];
                        A[i][j]=I[i][j];
                    }
                    cond=1;
                }
            }
        }
        for(j=0;j<=Linhas;j++){//Copia as colunas da primeira linha de A
            I[i][j]=A[i][j];
        }
        for(j=0;j<=Linhas;j++){//Dividir todos da Primeira linha pelo Elemento de Pivô.
            A[i][j]/=I[i][j];
        }
        for(i=1;i<Linhas;i++){//Zerar todos os Elementos da Coluna de Pivô.
        if(A[i][0]!=0){
            while(A[i][0]!=0){
                for(j=0;j<=Linhas;j++){
                    A[i][j]-=A[0][j];
                }
                
            }
        }
    }
    }
    return 0;
}