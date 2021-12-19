#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    cout << "Seja bem-vindo ao jogo da advinhação!" << endl << "Escolha sua Dificuldade:";
    cout << "Fácil(F)  Médio(M) Difícil(D)" << endl;
    
    char Dificuldade;
    cin >> Dificuldade;

    int MaxTries,Chute;
    double Pontos = 1000.0;
    bool Acertou = false;
  
    srand(time(NULL));
    const int SECRETNUM = rand() % 100;

    if(Dificuldade=='F'){
        MaxTries=15;
    }else if(Dificuldade=='M'){
        MaxTries=10;
    }else {
        MaxTries=5;
    }
    
    cout << "Você tem " << MaxTries << " tentativas." << endl;
    
    while(!Acertou && MaxTries>0){
        cout << "Tentativas restantes: "<< MaxTries << endl << "Qual seu Chute: ";
        cin >> Chute;

        Pontos = Pontos - abs(Chute - SECRETNUM)/2.0;

        if(Chute == SECRETNUM){
            cout << "Parabéns! Você acertou!" << endl;
            Acertou = true;
        }else if(Chute <SECRETNUM){
            cout << "Seu Chute foi menor que o número secreto!" << endl;
            MaxTries--;
        }else{
            cout << "Seu Chute foi maior que o número secreto!" << endl;
            MaxTries--;
        }
    }
    cout << "Fim de jogo!";
    if(Acertou){
        cout << "Você terminou com " << MaxTries << " tentativas restantes" << endl;
        cout.precision(2);
        cout << fixed;
        cout << "Sua pontuação foi de " << Pontos << endl;
        cout << "Obrigador por jogar!";
    }else{
        cout << "Não foi desssa vez! Tente Novamente!";
    }
}