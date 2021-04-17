#include <stdio.h>

int main(){

    int k,i,m,n,d,a,r=0;

    scanf("%d\n %d\n %d\n %d\n %d",&k,&i,&m,&n,&d);
    
    if(d!=0){
        for(a=1;a<=d;a++){
            if(k==0 || i==0 || m==0 || n==0){ 
                r++;
            }else if(a%k==0){
                r++;
            }else if(a%i==0){
                r++;
            }else if(a%m==0){
                r++;
            }else if(a%n==0){
                r++;
        }
    }
    }
    printf("%d",r);
    return 0;
}