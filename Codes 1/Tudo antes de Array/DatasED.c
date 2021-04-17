#include <stdio.h>

int main(){

    int d,m,a,d1,m1,a1,x1,x2,x3,aux,cont1=0;
    scanf("%d/%d/%d\n",&d,&m,&a);
    scanf(" %d/%d/%d",&d1,&m1,&a1);

    x1=d;x2=m;x3=a;
    
    if(a<a1){//Trocar até o final
        while(a<a1){
            if((a%4==0) && !(a%100==0 && a%400!=0)){//Troca de meses do ano Bissexto
                while(m<=12){
                    if(m==2){
                        if(d==29){d=1;m++;cont1++;}
                        else while(d<29){
                                d++;
                                cont1++; 
                            }m++;d=1;
                    }else if(m==4 || m==6 || m==9 || m==11){
                        if(d==30){d=1;m++;cont1++;}
                        else while(d<30){
                                d++;
                                cont1++; 
                            }m++;d=1;
                    }else{
                        if(d==31){d=1;m++;cont1++;}
                        else while(d<31){
                                d++;
                                cont1++; 
                            }m++;d=1;
                    }
                }if(m==13){d=1;m=1;a++;}
            }
            else{//Troca de meses do ano normal
                while(m<=12){
                    if(m==2){
                        if(d==28){d=1;m++;cont1++;}
                        else while(d<28){
                                d++;
                                cont1++; 
                            }m++;d=1;cont1++;
                    }else if(m==4 || m==6 || m==9 || m==11){
                        if(d==30){d=1;m++;cont1++;}
                        else while(d<30){
                                d++;
                                cont1++; 
                            }m++;d=1;cont1++;
                    }else{
                        if(d==31){d=1;m++;cont1++;}
                        else while(d<31){
                                d++;
                                cont1++; 
                            }m++;d=1;cont1++;
                    }
                }if(m==13){d=1;m=1;a++;}
            }
        }
    }
    if(a==a1){//Trocas até o valor correspondente.
        if((a%4==0) && !(a%100==0 && a%400!=0)){
            if(m<m1){
                while(m<m1){
                    if(m==2){
                        if(d==29){d=1;m++;cont1++;}
                        else while(d<29){
                                d++;
                                cont1++; 
                            }m++;d=1;
                    }else if(m==4 || m==6 || m==9 || m==11){
                        if(d==30){d=1;m++;cont1++;}
                        else while(d<30){
                                d++;
                                cont1++; 
                            }m++;d=1;
                    }else{
                        if(d==31){d=1;m++;cont1++;}
                            while(d<31){
                                d++;
                                cont1++; 
                            }m++;d=1;
                    }
                }if(m==m1){d=1;cont1++;}
            }
            if(m==m1){
                if(d<d1){
                    while(d<d1){
                        d++;
                        cont1++;
                    }
                }   
            }
        }
        else{
            if(m<m1){
                while(m<m1){
                    if(m==2){
                        if(d==28){d=1;m++;cont1++;}
                        else while(d<28){
                                d++;
                                cont1++; 
                            }m++;d=1;
                    }else if(m==4 || m==6 || m==9 || m==11){
                        if(d==30){d=1;m++;cont1++;}
                        else while(d<30){
                                d++;
                                cont1++; 
                            }m++;d=1;
                    }else{
                        if(d==31){d=1;m++;cont1++;}
                        else while(d<31){
                                d++;
                                cont1++; 
                            }m++;d=1;
                    }
                }if(m==m1){d=1;cont1++;}
            }
            if(m==m1){
                if(d<d1){
                    while(d<d1){
                        d++;
                        cont1++;
                    } 
                }  
            }
        }
    }

    printf("Estamos na data %d/%d/%d\n", d,m,a);
    printf("Passaram-se %d dias\n", cont1);
    
    aux=cont1;
    cont1/=2;
    while(cont1>0){
        x1++;
        cont1--;
        if((x3%4==0) && !(x3%100==0 && x3%400!=0)){
            if(x1==29 && x2==2){x1=1;x2++;}
            else if(x1==30 && (x2==4 || x2==6 || x2==9 || x2==11)){x1=1;x2++;}
            else if(x1==31 && x2==12){x1=1;x2=1;x3++;}
            else if(x1==31){x1=1;x2++;}
        }else{
            if(x1==28 && x2==2){x1=1;x2++;}
            else if(x1==30 && (x2==4 || x2==6 || x2==9 || x2==11)){x1=1;x2++;}
            else if(x1==31 && x2==12){x1=1;x2=1;x3++;}
            else if(x1==31){x1=1;x2++;}
        }
    }
    
    if(aux%2!=0){
        printf("%02d/%02d/%d 12:00",x1,x2,x3);
    }
    else{
        printf("%02d/%02d/%d 00:00",x1,x2,x3);
    }


    return 0;
}