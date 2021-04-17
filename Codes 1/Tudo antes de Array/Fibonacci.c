#include <stdio.h>
#include <math.h>

int main(){

    int N,num,Num1=0,Num2=1,i,p=1;
    scanf("%d",&N);

  
    if(N==2){
        printf("%d",N);
    }else{
        while((Num1+Num2)<=N){
        num=Num1+Num2;
        Num1=Num2;
        Num2=num;
        }printf("Valor de Fibonacci: %d\n",num);
        for(i=2;i<num;i++){
            if(num%i==0){
                p=0;
            }
        }
        while(p==0){
            num--;
            p=1;
            for(i=2;i<num;i++){
                if(num%i==0){
                    p=0;
                }
            }
        }printf("%d",num);
    }
    return 0;
}
    