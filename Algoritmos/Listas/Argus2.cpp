#include<bits/stdc++.h> 
using namespace std;

struct HeapNode{
    int ID;
    int Period;
    int TTime;
};

int heapsize = 0;
HeapNode unidades[1100];

bool compare(int i, int j){
    if(unidades[i].TTime > unidades[j].TTime) return false;
    else if(unidades[i].TTime < unidades[j].TTime) return true;
    else{
        if(unidades[i].ID > unidades[j].ID) return false;
        else return true;
    }
}

void bubble_up(int pos){
    int i = pos;
    while(i > 0 && compare(i, (i-1)/2)){
        int id1 = unidades[i].ID, id2 = unidades[(i-1)/2].ID;
        swap(unidades[i], unidades[(i-1)/2]);
        i = (i-1)/2;
    }
}

void insert(int ID, int Period){
    unidades[heapsize].TTime = Period;
    unidades[heapsize].ID = ID;
    unidades[heapsize].Period = Period;

    heapsize++;

    bubble_up(heapsize-1);
}

void heapify(int i, bool Comeco){
    if(Comeco){
        unidades[i].TTime+= unidades[i].Period;
    }
    int m = i, l = 2*i+1, r = l+1;
    if(l < heapsize && compare(l, m))
        m = l;
    if(r < heapsize && compare(r, m))
        m = r;
    if(m != i){
        int id1 = unidades[i].ID, id2 = unidades[m].ID;
        swap(unidades[i], unidades[m]);
        heapify(m, false);
    }
}

int main(){
    string Command;
    int Job, Value, K,i;
    while((cin >> Command) && (Command != "#")){
        cin >> Job >> Value;
        insert(Job,Value);
    }
    cin >> K;
    for(i=0; i<K; i++){
        cout << unidades[0].ID << endl;
        heapify(0, true);
    }
}
