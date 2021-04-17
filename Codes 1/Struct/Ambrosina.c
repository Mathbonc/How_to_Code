#include <stdio.h>
#include <string.h>

typedef struct {
int LED;
char Nome[101];
float Preco;
}Cardapio;

int main(){

    int N,a,b,Cod,cond=0,Qntd;
    float Pagar=0;
    scanf("%d",&N);
    Cardapio Produto[N];
    for(a=0;a<N;a++){
        scanf("%d", &Produto[a].LED);
        scanf(" %[^\n]", Produto[a].Nome);
        scanf("%f", &Produto[a].Preco);
    }
    
    
    while(scanf("%d",&Cod),scanf("%d",&Qntd),Cod!=0){
        if(Qntd>0){
            for(a=0;a<N;a++){
                if(Cod==Produto[a].LED){
                    cond++; 
                }
            }
            if(cond>0){
               for(a=0;a<N;a++){
                    if(Cod==Produto[a].LED){
                        Pagar+=Qntd*Produto[a].Preco;
                    }
                } 
            }
        }
    }
    
    
    printf("%.02f",Pagar); 
    return 0;
}