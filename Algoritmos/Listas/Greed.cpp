#include <bits/stdc++.h>
using namespace std;

typedef struct{
    int remaing_volume;
    long long int volume;
}can;

int main(){
    int n,i,j,volume;
    long long int volume_total=0, VolTemp;
    cin >> n;
    if(n==2){
        cout << "YES" << endl;
    }else{
        can Can[n];
        for(i=0;i<n;i++){
            cin >> Can[i].remaing_volume;
            volume_total+=Can[i].remaing_volume;
        }
        for(i=0;i<n;i++){
            cin >> Can[i].volume;
        }
        for(i=0;i<2;i++){
            for(j=i+1;j<n;j++){
                if(Can[i].volume<Can[j].volume){
                    VolTemp = Can[i].volume;
                    Can[i].volume = Can[j].volume;
                    Can[j].volume = VolTemp;
                }
            }
        }
        if((Can[0].volume+Can[1].volume)>=volume_total){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}