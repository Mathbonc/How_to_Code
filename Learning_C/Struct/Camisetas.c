#include <string.h>
#include <stdio.h>

typedef struct {
    char nome[101],cor[10],Tam;
}Pessoa;

typedef struct {
    Pessoa Aluno[60];
}turma;

int main(){

    int N,i,j,NTurma=0;
    char aux[10];
    turma Turma[100];

    while(scanf("%d",&N),N!=0){
        for(i=0;i<N;i++){
            scanf(" %[^\n]", Turma[NTurma].Aluno[i].nome);
            scanf(" %s %c", Turma[NTurma].Aluno[i].cor,&Turma[NTurma].Aluno[i].Tam);
        }
        for(i=0;i<N-1;i++){
            for(j=i+1;j<N;j++){
                if(Turma[NTurma].Aluno[i].cor<Turma[NTurma].Aluno[j].cor){
                    strcpy(aux,Turma[NTurma].Aluno[i].cor);
                    strcpy(Turma[NTurma].Aluno[i].cor,Turma[NTurma].Aluno[j].cor);
                    strcpy(Turma[NTurma].Aluno[j].cor,aux);
                }
            }
        }
        NTurma++;
    }   
    
    

    return 0;
}