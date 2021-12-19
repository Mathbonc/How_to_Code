#include "bits/stdc++.h"
using namespace std;

#define x first
#define y second
#define mp make_pair

const int MAXN = 10100;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

int root[MAXN], size[MAXN];

int find(int a){
    if(root[a] == a) return a;
    return root[a] = find(root[a]);
}

void join(int a, int b){
    a = find(a);
    b = find(b);

    if(a != b){
        if(size[a] < size[b]) root[b] = a;
        else root[a] = b;
        size[a] += size[b];
        size[b] += size[a];
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for(int K=1; K<=t; K++){
        int n, m, a;
        cin >> n >> m >> a;

        int mst = 0, ans = 0;
        priority_queue<iii, vector<iii>, greater<iii> > pq;
        for(int i = 0; i <= n; i++){
            root[i] = i, size[i] = 0;
        }
        for(int i = 0 ; i < m; i++){
            int u, v, w;
            cin >> u >> v >> w;
            if(w < a) pq.push(mp(w, mp(u, v)));
        }
        while(!pq.empty()){
            int u, v, w;
            w = pq.top().x, u = pq.top().y.x, v = pq.top().y.y; 
            pq.pop();

            if(find(u) != find(v)){
                mst += w;
                join(u, v);
            }
        }
        for(int i = 1; i <= n; i++){
            find(i);
            if(root[i] == i) ans++;
        }
        printf("Case #%d: %d %d\n", K, mst + ans*a, ans);
    }
    return 0;
}