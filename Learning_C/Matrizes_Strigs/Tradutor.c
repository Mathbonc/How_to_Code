#include <stdio.h>
#include <string.h>

int main(){
    //PRIMEIRA ENTRADA//
    int n,m;
    int i,j,y,a,aux=0;
    scanf("%d %d",&n,&m);
    //SEGUNDA ENTRADA//
    char ASub[n][1001],Sub[n][1001];
    for(i=0;i<n;i++){
        scanf(" %s -> %s", ASub[i],Sub[i]);
    }
    //TERCEIRA ENTRADA//
    char Texto[m][1001],Resp[m][1001],NS[1001];
    for(i=0;i<m;i++){
        scanf(" %[^\n]", Texto[i]);
    }
    //SUBSTITUIÇÕES//
    for(y=0;y<m;y++){
        for(a=0;a<strlen(Texto[y]);a++){
            if(Texto[y][a+1]!=' '){  
                while(Texto[y][a+1]!=' '){
                    NS[aux]=Texto[y][a];
                    a++;aux++;
                }aux=0;
                for(i=0;i<n;i++){
                    if(strlen(ASub[i])>1){   
                        if(strcmp(NS,ASub[i])==0){
                            strcat(Resp[y],Sub[i]);
                            break;
                        }
                        else{
                            for(j=0;j<strlen(NS);j++){
                                if(NS[j]==ASub[i][0]){
                                    Resp[y][a]=Sub[i][0];
                                }
                            }
                        }
                    }
                }memset(NS,'\0',strlen(NS));

            }
        }
    }


    return 0;
}