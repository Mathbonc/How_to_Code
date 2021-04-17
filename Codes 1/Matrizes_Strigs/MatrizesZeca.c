#include <stdio.h>

int main(){

    int MatrixA[3][3],MatrixV[3][3],MatrixR[3][3],i,j,k,l=0,aux=0;
    //Scanf das duas Matrizes
    for(i=0;i<3;i++){
        scanf("%d %d %d",&MatrixA[i][0],&MatrixA[i][1],&MatrixA[i][2]);
    }
    for(j=0;j<3;j++){
        scanf("%d %d %d",&MatrixV[j][0],&MatrixV[j][1],&MatrixV[j][2]);
    }
    //Multiplicação
    for(i=0;i<3;i++){//Ciclo da Linha de MatrixA
        for(j=0;j<3;j++){//Ciclo da Coluna de MatrixV
            for(k=l=0;k<3;k++,l++){//k = Coluna de A; l = Linha de V
                aux+=MatrixA[i][k]*MatrixV[l][j];
            }
            MatrixR[i][j]=aux;
            aux=0;
        }
    }
    //Saída
    for(i=0;i<3;i++){
        printf("%d %d %d",MatrixR[i][0],MatrixR[i][1],MatrixR[i][2]);
        printf("\n");
    }
    return 0;
}