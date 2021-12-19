#include <stdio.h>

int main(){

    char latao[4][5];
    int i;
    printf("Digite quatro strings:\n");
    for(i=0;i<4;i++){
        scanf(" %s", latao[i]);
    }
    for(i=0;i<4;i++){
        printf("String %d:",i+1);
        printf("%s \n", latao[i]);
    }
}