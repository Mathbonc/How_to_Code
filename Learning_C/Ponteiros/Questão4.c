#include <stdio.h>
#include <stdlib.h>

int main(){

    int vet[5]={10,20,30,40,50};
    int *p=NULL;
    p=vet;

    for(;p<=&vet[4];p++){
        printf("%d\n",*p);
    }

    return 0;
}