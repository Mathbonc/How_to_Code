#include <stdio.h>

int main(){

    int a,b,p=0,i,val,val2,val3,cont=0;
    scanf("%d %d", &a,&b);
    val=a;
    
    while(p==0){
        val--;p=1;
        for(i=2;i<val;i++){
            if(val%i==0){p=0;}
        }
    }
    p=0;val2=val;
    while(p==0){
        val2++;p=1;
        for(i=2;i<val2;i++){
            if(val2%i==0){p=0;}
        }
    }
    p=0;val3=val2;
    while(p==0){
        val3++;p=1;
        for(i=2;i<val3;i++){
            if(val3%i==0){p=0;}
        }
    }
    while(val2<=b){
        if((val+val3)%2==0){
            if((val+val3)/2==val2){cont++;}
        }
        val=val2;val2=val3;p=0;
        while(p==0){
            val3++;p=1;
            for(i=2;i<val3;i++){
                if(val3%i==0){p=0;}
            }
        }
    }
    printf("%d",cont);
    return 0;
}
    