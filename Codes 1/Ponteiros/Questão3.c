#include <stdio.h>
#include <stdlib.h>

int main(){

    int vet[5]={10,20,30,40,50},i;
    int *vetdin=NULL;

    vetdin=(int *) malloc(5*sizeof(int));
    if(vetdin!=NULL){
        printf("Size of Vet: %d  Size of Vetdin: %d\n",sizeof(vet),sizeof(vetdin));
    }else{
        printf("Alocação mal-sucedida.");
        exit(1);
    }

    for(i=0;i<5;i++){
        vetdin=(int*) realloc(vetdin,vet[i]);
        if(vetdin==NULL){
            printf("Alocação mal-sucedida.");
            exit(1);
        }else{
            printf("Size of Vetdin: %d\n",sizeof(vetdin));
        }
    }
    free(vetdin);

    printf("O tamanho de Vetdin nao muda pois o ponteiro aponta apenas pra uma posiçao(primeira), que tem sizeof(int) que é 4\n");

    return 0;
}