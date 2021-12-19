#include <iostream>
using namespace std;
const long long INF = 1e18+5;

void Possibilidades(long long *Contador, int moedas[], int valor,int *iteracao){
    (*iteracao)++;
    if(valor==0){
        (*Contador)++;
        return;
    }
    for(int i=0; i<5; i++){// para todas as moedas
        if(valor-moedas[i]>=0){
            printf("Iteracao %d: %d - %d = %d\n", (*iteracao),valor, moedas[i], (valor-moedas[i]));
            Possibilidades(Contador, moedas, (valor-moedas[i]), iteracao);
        }else{
            return;
        }
    }
    return;
}

int main (){
    int qntdMoedas = 5;
	int moedas [qntdMoedas] = {1,5,10,25,50};
	int valor;
    long long Contador = 0;
    int iteracao = 0;

    while(cin >> valor && !cin.eof()){
        Possibilidades(&Contador, moedas, valor, &iteracao);
        cout << Contador << endl;
        Contador = 0;
    }
	return 0;
}
