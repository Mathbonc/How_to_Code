#include <stdio.h>
#include <stdlib.h>

int main(){

    int n=42;
    int *p=NULL;
    p=&n;

    printf("Endereco de n: %p  Valor de n: %d\n", &n,n);
    printf("Valor de p: %p Valor do Endereco: %d\n", p,*p);
    printf("Endereco de p: %p\n",&p);
    printf("Endereco do Valor de p: %p Valor do Endereco de p:%p\n",&*p,*&p);
    printf("No primeiro caso, estamos acessando o Endereco do Valor de p, que seria 42, e seu endereco == &n\n"
          "No segundo caso, estamos vendo o Valor do Endereco de p, queria o proprio p, porem p=&n, logo sao iguais.");
    return 0;
}