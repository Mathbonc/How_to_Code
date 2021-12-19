#include <iostream>
using namespace std;

typedef long long int llt;

llt Absolute (llt X1, llt X2){
    if((X1-X2)<0){
        return (X2-X1);
    }else{
        return (X1-X2);
    }
}

int main(){
    int N,M,i,j;
    while(cin >> N && !cin.eof()){
        llt book[N]={},book1[2]={};
        for(i=0;i<N;i++){
            cin >> book[i];
        }
        cin >> M;

        book1[0]={-1};
        book1[1]={-1};
        
        for(i=0;i<N-1;i++){
            for(j=i+1;j<N;j++){
                if((book[i]+book[j])==M){
                    if(book1[0]==-1 || Absolute(book[i],book[j])<Absolute(book1[0],book1[1])){
                        book1[0]=book[i];
                        book1[1]=book[j];
                    }
                }
            }
        }
        
        if(book1[0]<=book1[1]){
            cout << "Peter should buy books whose prices are " << book1[0] << " and " << book1[1] << ".\n";
        }else{
            cout << "Peter should buy books whose prices are " << book1[1] << " and " << book1[0] << ".\n";
        }
        cout << endl;
    }
}