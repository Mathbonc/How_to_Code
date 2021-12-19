#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18+5;

vector<long long> possibilidades(int valor, vector<long long> Numero, int moedas[]){
    for(int i=0; i<5; i++){
        for(int j=moedas[i]; j<7500; j++){
            Numero[j] += Numero[j-moedas[i]];
        }
    }
    return Numero;
}

int main (){
    int qntdMoedas = 5;
	int moedas [qntdMoedas] = {1,5,10,25,50};
	int valor;
    vector<long long> Numeros(7500);
    Numeros[0]=1;
    Numeros = possibilidades(valor, Numeros, moedas);
    while(cin >> valor && !cin.eof()){
        cout << Numeros[valor] << endl;
    }
	return 0;
}