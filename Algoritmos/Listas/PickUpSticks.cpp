#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    while(cin >> n >> m && (m!=0 || n!=0)){
        vector<vector<int> > adj(n); // Lista de adjacência
        vector<int> Dependency(n,0); // Vetor, de nome "Dependency" e tamanho "n", inicializado com 0
        vector<int> ordem;
        queue<int> FilaComPompa;

        int a,b;
        for(int i = 0; i<m; i++){
            cin >> a >> b;
            a--;b--;
            adj[a].push_back(b); // Checa o vetor de número "a", pra armazenar "b" nesse vetor
            Dependency[b]++;  
        }

        for(int i = 0; i<n ; i++){  //Checa os "palitos que podem ser retirados", ou seja, não têm dependências
            if(Dependency[i] == 0){
                FilaComPompa.push(i);
            }
        }

        while(!FilaComPompa.empty()){
            int Atual = FilaComPompa.front();
            FilaComPompa.pop();

            ordem.push_back(Atual);

            for(int to: adj[Atual]){
                Dependency[to]--;
                if(Dependency[to] == 0){
                    FilaComPompa.push(to);
                }
            }
        }
        if(ordem.size()<n){
            cout << "IMPOSSIBLE" << endl;
        }else{
            for(int i = 0; i<ordem.size();i++){
                cout << ordem[i]+1 << endl;
            }
        }

    }
}

