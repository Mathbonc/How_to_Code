#include <stdio.h>
/*Situação atual do programa:
    -Trocas dias,meses,anos até a=a1, contando os dias.
*/

int main(){

    int d,m,a,d1,m1,a1,x,cont1=0;
    scanf("%d/%d/%d\n",&d,&m,&a);
    scanf(" %d/%d/%d",&d1,&m1,&a1);
    
    if(a<a1){//Trocar até o final
        while(a<a1){
            if((a%4==0) && !(a%100==0 && a%400!=0)){//Troca de meses do ano Bissexto
                while(m<=12){
                    if(m==2){
                        while(d<29){
                            d++;
                            cont1++; 
                        }m++;d=1;
                    }else if(m==4 || m==6 || m==9 || m==11){
                        while(d<30){
                            d++;
                            cont1++; 
                        }m++;d=1;
                    }else{
                        while(d<31){
                            d++;
                            cont1++; 
                        }m++;d=1;
                    }
                }if(m==13){d=1;m=1;a++;}
            }
            else{//Troca de meses do ano normal
                while(m<=12){
                    if(m==2){
                        while(d<28){
                            d++;
                            cont1++; 
                        }m++;d=1;cont1++;
                    }else if(m==4 || m==6 || m==9 || m==11){
                        while(d<30){
                            d++;
                            cont1++; 
                        }m++;d=1;cont1++;
                    }else{
                        while(d<31){
                            d++;
                            cont1++; 
                        }m++;d=1;cont1++;
                    }
                }if(m==13){d=1;m=1;a++;}
            }
        }
    }
    else{//Trocas até o valor correspondente.
        
    }
    printf("Estamos na data %d/%d/%d\n", d,m,a);
    printf("Passaram-se %d dias", cont1);


    return 0;
}