#include <iostream>
#include <vector>
using namespace std;

int NSoluçao;

void mostrarTabuleiro(vector<vector<int> > & tab, int N){
    for(int i=0; i<N ; i++){
        for(int j=0; j<N ; j++){
            if(tab[i][j]==1){
                cout << "R\t"; 
            }else{
                cout << "-\t";
            }
        }
        cout << "\n\n";
    }
    cout << "\n";
}

bool Seguro(vector<vector<int> > & tab, int N, int lin, int col){
    int i,j;
    for(i=0;i<N;i++){
        if(tab[lin][i]==1){
            return false;
        }
    }
    for(i=0;i<N;i++){
        if(tab[i][col]==1){
            return false;
        }
    }
    //Verifica a diagonal de cima e de baixo
    for(i=lin, j=col; i>=0 && j>=0; i--,j--){
        if(tab[i][j]==1){
            return false;
        }
    }
    for(i=lin, j=col; i<N && j<N; i++,j++){
        if(tab[i][j]==1){
            return false;
        }
    }
    //Verifica a outra diagonal
    for(i=lin, j=col; i>=0 && j<N; i--,j--){
        if(tab[i][j]==1){
            return false;
        }
    }
    for(i=lin, j=col; i<N && j>=0; i++,j++){
        if(tab[i][j]==1){
            return false;
        }
    }
    return true;
}

void executar(vector<vector<int> > & tab, int N, int col){
    if(col == N){
        cout << "Solucao " << NSoluçao + 1 << ":\n\n";
        mostrarTabuleiro(tab,N);
        NSoluçao++;
        return; 
    }
    for(int i=0; i<N; i++){
        if(Seguro(tab, N, i ,col)){
            tab[i][col] = 1;
            executar(tab, N, col+1);
            //remover a rainha em caso de backtracking
            tab[i][col] = 0;
        }
    }
}