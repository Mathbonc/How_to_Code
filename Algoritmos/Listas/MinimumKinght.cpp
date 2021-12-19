#include <bits/stdc++.h>
using namespace std;

bool isInRange(int x, int y){
    if(x>=0 && x<8 && y>=0 && y<8){
        return true;
    }else{
        return false;
    }
}


int main(){
    int T;
    cin >> T;
    string Pos1, Pos2;
    vector<pair<int,int>> Direct = {{-2,1}, {-2,-1}, {-1,+2}, {-1,-2}, {2,1}, {2,-1}, {1,2}, {1,-2}}; //Vetor par (Direções)
    int x0,y0,x1,y1;

    for(int i=0; i<T; i++){
        queue<pair<pair<int,int>,int>> Fila;  //Matriz de fila 
        vector<vector<bool>> Visited(9,vector<bool>(9,false)); //Inicializa uma matriz bool, com 9 linhas e 9 colunas todas inicializadas com false
        
        cin >> Pos1 >> Pos2;
        x0 = Pos1[0] - 'a'; //Tira "a" para transformar em int
        y0 = Pos1[1] - '1'; //Mesma coisa
        x1 = Pos2[0] - 'a';
        y1 = Pos2[1] - '1';

        Fila.push({{x0,y0},0});
        Visited[x0][y0] = true;

        int Ans;
        while(!Fila.empty()){
            pair<pair<int,int>,int> Curr;
            Curr = Fila.front();
            Fila.pop();

            if(Curr.first.first == x1 && Curr.first.second == y1){
                Ans = Curr.second;
                break;
            }

            for(auto E: Direct){
                pair<pair<int,int>,int> Next = Curr;
                Next.first.first += E.first;
                Next.first.second += E.second;
                Next.second++;
                
                if(isInRange(Next.first.first,Next.first.second) && Visited[Next.first.first][Next.first.second]!=1){
                    Visited[Next.first.first][Next.first.second]=1;
                    Fila.push(Next);
                }
            }
        }
        cout << Ans << endl;
    }
}