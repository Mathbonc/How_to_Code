#include <stdio.h>
#include <stdlib.h>

   
int main(){

    int vet[5]={10,20,30,40,50},i;
    int *p;
    p = vet;
    
    printf("Endereco de Vet: %p Endereco de p: %p\n",&vet,p);
    
    printf("Usando p[]:\n");
    for(i=0;i<5;i++){
        printf("Valor %d: %d\n", i+1,p[i]);
    }
    printf("Usando *p:\n");
    for(i=0;i<5;i++){
        printf("Valor %d: %d\n", i+1,*(p+i));
    }
    printf("Usando vet[]:\n");
    for(i=0;i<5;i++){
        printf("Valor %d: %d\n", i+1,vet[i]);
    }

   

    

    return 0;
}