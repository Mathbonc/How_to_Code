#include <bits/stdc++.h>
using namespace std;
const int PESOMAX = 31;

int main(){
    int T;
    cin >> T;
    int MelhorPeso[PESOMAX];
    
    for(int k=0; k<T; k++){
        int nItems;
        int Total = 0, Pessoas;
        int peso;
        
        cin >> nItems;
        
        for (int i = 0; i < PESOMAX; ++i){
            MelhorPeso[i] = 0;
        }    
        for (int item = 0; item < nItems; ++item){
            int peso_item, valor_item;
            cin >> valor_item >> peso_item;
            
            for (int peso=PESOMAX-1; peso>=peso_item; --peso){
                MelhorPeso[peso] = max(MelhorPeso[peso], MelhorPeso[peso-peso_item] + valor_item);
            }
        }
        
        cin >> Pessoas;
        
        for (int i = 0; i < Pessoas; ++i){
            cin >> peso;
            Total += MelhorPeso[peso];
        }
        
        cout << Total << endl;
    }
}