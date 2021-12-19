#include "bits/stdc++.h"
using namespace std;
#define mp make_pair

typedef long long ll;
typedef pair<ll,ll> ii;
const ll INF = 1e18 + 5;

//Implementando o Dijkstra
int dijkstra(int nVtx, int S, int T, vector<vector<ii> >& adj){
    vector<ll> d(nVtx, INF);  //VETOR DE TAMANHO N, INICIALIZADO COM INF
    priority_queue<ii, vector<ii>, greater<ii> > ListaPrio;
    d[S] = 0;
    ListaPrio.push(mp(d[S], S)); //Menor Distância e Vértice S 

    while(!ListaPrio.empty()){
        ii aux = ListaPrio.top();
        ListaPrio.pop();
        int y = aux.second;

        if(d[y] < aux.first) continue;

        for(auto e : adj[y]){
            ll w = e.second;
            int v = e.first;

            if(d[y] + w < d[v]) {
                d[v] = d[y] + w;
                ListaPrio.push(mp(d[v], v));
            }
        }
    }
    return ((d[T] == INF) ? -1 : d[T]);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tests;

    cin >> tests;
    for(int ct = 1; ct <= tests; ct++){
        ll n,m,S,T;
        cin >> n >> m >> S >> T;
        vector<vector<ii> > adj_list(n);

        for(int i = 0; i < m; i++){
            int a ,b ,c;
            cin >> a >> b >> c;
            adj_list[a].push_back(mp(b, c));
            adj_list[b].push_back(mp(a, c));
        }
        ll Ans = dijkstra(n, S, T, adj_list);

        if(Ans == -1){
            cout << "Case #"<< ct <<": unreachable" << endl;
        }
        else{
            cout << "Case #"<< ct <<": "<< Ans << endl;
        }

        adj_list.clear();
    }
}