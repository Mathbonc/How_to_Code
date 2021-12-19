#include <stdio.h>

int main (){

    unsigned int dia, mes, ano;
    scanf("%d %d %d", &dia,&mes,&ano);

    if(dia==0 || mes==0 || ano==0){
        printf("invalida");
    }else if(dia>31 || mes>12){
        printf ("invalida");
    }else if((ano%4==0) && !(ano%100==0 && ano%400!=0)){
        if(mes==2){
            if(dia>29){
                printf("invalida");
            } else printf ("valida");
        }else if(mes==4 || mes==6 || mes==9 || mes==11){
            if(dia>30){
                printf("invalida");
            }else printf ("valida");
        }
    }else if(mes==2){
            if(dia>28){
                printf("invalida");
            }else printf ("valida");
    }else if(mes==4 || mes==6 || mes==9 || mes==11){
        if(dia>30){
                printf("invalida");
         }
    }else{
        printf("valida");
    }

    return 0;
}