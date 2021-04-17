#include <stdio.h>

int main(){

    int N,i,j,aux;
    scanf("%d",&N);
    char Matriz[N][N],MatrizT[N][N];

    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            scanf(" %c", &Matriz[i][j]);
        }
    }
    //Formando a Tranposta//
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            MatrizT[i][j]=Matriz[j][i];
        }
    }
    //Pulando 1 letra
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            if(MatrizT[i][j]>='a' && MatrizT[i][j]<='z'){//Letras minusculas
                if(MatrizT[i][j]=='y'){
                    MatrizT[i][j]='a';
                }else if(MatrizT[i][j]=='z'){
                    MatrizT[i][j]='b';
                }else{
                    MatrizT[i][j]+=2;
                }
            }
        }
    }
    
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            printf("%c", MatrizT[i][j]);
        }
    }
    return 0;
}