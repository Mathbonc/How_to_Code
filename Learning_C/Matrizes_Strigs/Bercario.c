#include <stdio.h>
#include <math.h>

int main(){

    int t,n,m,aux2,bb=0,cri=0,cho=0,i,j,y;//bb->Triangular //cri->quadrático //cho->Penta
    float aux;
    scanf("%d",&t);
    for(y=0;y<t;y++){
        scanf("%d %d",&n,&m);
        int Matriz[n][m];
        //LEITURA DA MATRIZ//
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                scanf("%d",&Matriz[i][j]);
            }
        }
        //CHECAR OS NÚMEROS//
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                aux=sqrt(8*Matriz[i][j]+1);
                aux2=aux;
                if(aux-aux2==0){
                    if((aux2-1)%2==0){
                        cri++;
                    }
                }else{
                    aux=sqrt(16*Matriz[i][j]);
                    aux2=aux;
                    if(aux-aux2==0){
                        if(aux2%4==0){
                            bb++;
                        }
                    }else{
                        aux=sqrt(24*Matriz[i][j]+1);
                        aux2=aux;
                        if(aux-aux2==0){
                            if((aux2+1)%6==0){
                                cho++;
                            }
                        }
                    }
                }
            }
        }
        //Printar//
        printf("Temos %d crianças\nTemos %d bebês\n",cri,bb);
        if(cho>0){
            printf("Hoje o bebê vai chorar sozinho...\n");
        }else{
            printf("Oba! Kinho vai trabalhar hoje.\n");
        }
        //Resetar//
        bb=cri=cho=0;
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                Matriz[i][j]=0;
            }
        }
        
    }

    return 0;
}