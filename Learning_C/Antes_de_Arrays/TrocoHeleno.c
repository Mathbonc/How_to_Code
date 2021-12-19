#include <stdio.h>

int main(){

    int n,u=0,c=0,d=0,count=0;
    scanf("%d",&n);
    while(n!=0){
        if(n>=10){
            while(n>=10){
                n-=10;
                count++;
                d++;
            }
        }if(n>=5 && n<10){
            while(n>=5){
                n-=5;
                count++;
                c++;
            }
        }if(n>0 && n<5){
            while(n>0){
                n--;
                count++;
                u++;
            }
        }
        printf("%d\n%d %d %d\n",count,u,c,d);
        count=0,u=0,c=0,d=0;
        scanf(" %d", &n);
    }

    return 0;
}
    
    
