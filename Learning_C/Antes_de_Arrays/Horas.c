#include <stdio.h>

int main(){

    int H,M; 
    scanf("%d",&H);
    scanf("%d",&M);

    if(H==0){
        H=12;
        printf("%02d\n%02d\nam", H,M);
    }else if(H==12){
        printf("%02d\n%02d\npm", H,M);
    }else if(H>12){
        H=H%12;
        printf("%02d\n%02d\npm",H, M);
    }else printf("%02d\n%02d\nam",H, M);
    
    return 0;
}