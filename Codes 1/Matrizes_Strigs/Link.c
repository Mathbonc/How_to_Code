#include <stdio.h>
#include <string.h>


int main(){

    int i,j,aux1=0,cont=0;
    char Texto[110],aux[110];

    scanf(" %[^\n]", Texto);

    for(i=0;i<strlen(Texto);i++){
        if(Texto[i]=='z' || Texto[i]=='Z'){
            if(Texto[i+1]=='e' || Texto[i+1]=='E'){
                if(Texto[i+2]=='e' || Texto[i+2]=='E'){
                    while(Texto[i+2]=='e' || Texto[i+2]=='E'){
                        i++;
                    }
                }
                if(Texto[i+2]=='l' || Texto[i+2]=='L'){
                    if(Texto[i+3]=='l' || Texto[i+3]=='L'){
                        while(Texto[i+3]=='l' || Texto[i+3]=='L'){
                            i++;
                        }
                    }
                    if(Texto[i+3]=='d' || Texto[i+3]=='D'){
                        if(Texto[i+4]=='d' || Texto[i+4]=='D'){
                            while(Texto[i+4]=='d' || Texto[i+4]=='D'){
                                i++;
                            }
                        }
                        if(Texto[i+4]=='a' || Texto[i+4]=='A'){
                            cont++;
                        }
                    }   
                }
            }
        }   
    }
    if(cont>=1){
            printf("Link Bolado");
        }else{
            printf("Link Tranquilo");
        }

    return 0;
}