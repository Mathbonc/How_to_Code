#include <stdio.h>

int main(){

    int x,y,n,i,j,x1=0,y1=0,C,B,D,E,token=0;
    C=B=D=E=0;
    scanf("%d %d", &x, &y);
    scanf("%d", &n);
    char Com[n+1];
    scanf(" %s",Com);


   for(i=0;i<n;i++){
        if(Com[i]=='C'){
            C++;
        }else if(Com[i]=='B'){
            B++;
        }else if(Com[i]=='E'){
            E++;
        }else if(Com[i]=='D'){
            D++;
        }

        if(x>0){
            if(E>=x){token++;}
        }else if(x<0){
            if(D>=(-1)*x){token++;}
        }else{}
        if(y>0){
            if(B>=y){token++;}
        }else if(y<0){
            if(C>=(-1)*y){token++;}
        }else{}
    }

    
    if(token>=2){
        for(i=0;i<n;i++){
            if(Com[i]=='C'){
                C++;
            }else if(Com[i]=='B'){
                B++;
            }else if(Com[i]=='E'){
                E++;
            }else if(Com[i]=='D'){
                D++;
            }
        }
        if(C>0 && B>0){
            printf("S");
        }else if(E>0 && D>0){
            printf("S");
        }else if(E>x || D>-x || B>y || C>-y){
            printf("S");
        }else{
            printf("N");
        }
        
    }
    else{
        printf("N");
    }

    return 0;
}