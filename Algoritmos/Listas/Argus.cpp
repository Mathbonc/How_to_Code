#include<bits/stdc++.h> 
using namespace std;
 
// Prototype of a utility function to swap two integers
void swap(int *x, int *y);

struct HeapNode{
    int ID;
    int Period;
    int TTime;
    HeapNode(int x, int y): ID(x),Period(y), TTime(y){}
};

// A class for Min Heap
class MinHeap {
    int *elem; // pointer to array of elements in heap
    int capacity; // maximum possible size of min heap
    int heap_size; // Current number of elements in min heap
public:
    // Constructor
    MinHeap(int capacity);
  
    // to heapify a subtree with the root at given index
    void MinHeapify(int );
  
    int parent(int i) { return (i-1)/2; }
  

    int left(int i) { return (2*i + 1); }
    int right(int i) { return (2*i + 2); }
    int getMin() { return elem[0]; }
    void deleteKey(int i);
    void Register(int k);
};
  
    // Constructor
    MinHeap::MinHeap(int cap) {
        heap_size = 0;
        capacity = cap;
        elem = new int[cap];
    }
  
    void MinHeap::Register(int k) {
        if (heap_size == capacity) {
            cout << "\nError (Insert Key)\n";
            return;
        }
    
        // First insert the new key at the end
        heap_size++;
        int i = heap_size - 1;
        elem[i] = k;
    
        // Fix the min heap property if it is violated
        while (i != 0 && elem[parent(i)] > elem[i]) {
        swap(&elem[i], &elem[parent(i)]);
        i = parent(i);
        }
    }

  
  
// This function deletes key at index i. It first reduced value to minus
// infinite, then calls extractMin()
void MinHeap::deleteKey(int i){
    decreaseKey(i, INT_MIN);
    extractMin();
}
  
// A recursive method to heapify a subtree with the root at given index
// This method assumes that the subtrees are already heapified
void MinHeap::MinHeapify(int i) {
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && elem[l] < elem[i])
        smallest = l;
    if (r < heap_size && elem[r] < elem[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(&elem[i], &elem[smallest]);
        MinHeapify(smallest);
    }
}
  
// A utility function to swap two elements
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main(){
    MinHeap Argus(1000);
    char Command;
    while((cin >> Command) && (Command != '#')){

    }
}