#include <bits/stdc++.h>
using namespace std;

void Combinacao(int pos, int &t, int &n, int Vector[], int &QntdResp, int Soma, vector<int> DP[]){
    if (Soma==t){
        DP[QntdResp+1] = DP[QntdResp];
        QntdResp++;
        return;
    }
    for(int i = pos; i < n; i++){
        if(Soma + Vector[i] <= t){
            Soma += Vector[i];
            DP[QntdResp].push_back(Vector[i]);
            Combinacao(i + 1, t, n, Vector,QntdResp, Soma, DP);
            Soma -= Vector[i];
            DP[QntdResp].pop_back();
        }
    }
}

bool Comparar(vector<int> a, vector<int> b){
    for(int i = 0; i < a.size(); i++){
        if (a[i] == b[i]){    
            continue;
        }
        return a[i] > b[i];
    }
    return a.size() > b.size();
}


int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t, n, Vector[100];
    vector<int> DP[10000];

    while(cin >> t >> n && (t!=0 || n!=0)){
        int QntdResp = 0;
        for(int i = 0; i < n; i++){
            cin >> Vector[i];
        }
        for(int i=0; i<n; i++){
            DP[i].clear();
        }
        Combinacao(0, t, n, Vector, QntdResp, 0, DP);

        cout << "Sums of " << t << ":\n";
        if (QntdResp == 0){
            cout << "NONE" << endl;
        }else{
            sort(DP, DP + QntdResp, Comparar);
            cout << DP[0][0];
            for(int i = 1; i < DP[0].size(); i++){
                cout << "+" << DP[0][i];
            }
            cout << endl;
            for(int i = 1; i < QntdResp; ++i){
                if (DP[i] != DP[i-1]){
                    cout << DP[i][0];
                    for(int j = 1; j < DP[i].size(); j++){
                        cout << "+" << DP[i][j];
                    }
                    cout << endl;
                }
            }
        }
    }
}