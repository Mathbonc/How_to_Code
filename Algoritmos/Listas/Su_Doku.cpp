#include <bits/stdc++.h>
using namespace std;
#define Tab_size 9

bool EspaçoLivre(int Tabuleiro[Tab_size][Tab_size], int &lin, int &col, int n){
    for (lin=0; lin<n*n; lin++){
        for (col=0; col<n*n; col++){
            if (Tabuleiro[lin][col] == 0){
                return true;
            }
        }
    }
    return false;
}

bool LinhaLivre(int Tabuleiro[Tab_size][Tab_size], int lin, int num, int n){
    for (int col=0; col<n*n; col++){
        if (Tabuleiro[lin][col] == num){
            return true;
        }
    }
    return false;
}

bool ColunaLivre(int Tabuleiro[Tab_size][Tab_size], int col, int num, int n){
    for (int lin=0; lin<n*n; lin++){
        if (Tabuleiro[lin][col] == num){
            return true;
        }
    }
    return false;
}

bool QuadradoLivre(int Tabuleiro[Tab_size][Tab_size], int squareStartRow, int squareStartCol, int num, int n){
    for (int lin=0; lin<n; lin++){
        for (int col=0; col<n; col++){
            if (Tabuleiro[lin+squareStartRow][col+squareStartCol] == num){
                return true;
            }
        }
    }
    return false;
}

bool Livre(int Tabuleiro[Tab_size][Tab_size], int lin, int col, int num, int n){
    return !LinhaLivre(Tabuleiro, lin, num, n) && !ColunaLivre(Tabuleiro, col, num, n) && !QuadradoLivre(Tabuleiro, lin - lin % n, col - col % n, num, n) && Tabuleiro[lin][col] == 0;
}

bool Solucao(int Tabuleiro[Tab_size][Tab_size], int n){
    int lin, col, num;
    if(!EspaçoLivre(Tabuleiro, lin, col, n)){
        return true;
    }
    for (num=1; num<=n*n; num++){
        if (Livre(Tabuleiro, lin, col, num, n)){
            Tabuleiro[lin][col] = num;
            if (Solucao(Tabuleiro, n)){
                return true;
            }
            Tabuleiro[lin][col] = 0;
        }
    }
    return false;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    int Tabuleiro[Tab_size][Tab_size], n, flag = 0;

    while (cin >> n){
        if (flag != 0){
            cout << endl;
            flag = 1;
        }
        for (int i=0; i<n*n; i++){
            for (int j=0; j<n*n; j++){
                cin >> Tabuleiro[i][j];
            }
        }

        if (n == 1){
            cout << "1" << endl;
        }else{
            if (Solucao(Tabuleiro, n) == 1){
                for (int lin=0; lin<n*n; lin++){
                    for (int col=0; col<n*n; col++){
                        cout << Tabuleiro[lin][col];
                        if (col<n*n-1){
                            cout << " ";
                        }
                    }
                    cout << endl;
                }
            }
            else{
                cout << "NO SOLUTION" << endl;
            }
        }
        flag = 1;
    }
}