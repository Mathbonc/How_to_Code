#include <stdio.h>

int main(){

    int rigante;
    char mander;
    scanf("%d %c", &rigante, &mander);

    if((0<=rigante && rigante<=99) && (33<=mander && mander<=64)){
        printf ("Caminhão 1");
    }else if((rigante%2==0) && (mander=='A' || mander=='E' || mander=='I' || mander=='O' || mander=='U' || mander=='a' || mander=='e' || mander=='i' || mander=='o' || mander=='u')){
        printf("Caminhão 2");
    }else if ((rigante%2!=0) && ('A'<=mander && mander<='Z')){
        printf ("Caminhão 3");
    }else{
        printf ("Caminhão 4");
    }
    return 0;
}