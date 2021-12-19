#include <stdio.h>
#include <stdlib.h>

typedef struct{

    int matricula;
    float nota;
    char curso[20];

}Aluno;


int main()
{
    Aluno aluno = {1102,9.9,"eng da computacao"},*paluno = &aluno;

    printf("%d %.2f %s\n",paluno->matricula,paluno->nota,paluno->curso);

    return 0;
}