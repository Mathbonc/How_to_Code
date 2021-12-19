#include <bits/stdc++.h>
using namespace std;

//Implementando Link//
class Link{
	public:
	    int element; //Valor deste
	    Link *next; //Próximo Node
	    //Constructor
	    Link(const int& elemval, Link* nextval = NULL){
	        element = elemval; 
	        next = nextval;
	    }
	    Link(Link *nextval = NULL){
	        next = nextval;
	    }
};

// Linked queue implementation
class LQueue{
private:
    Link *front; // Pointer to front queue node
    Link *rear; // Pointer to rear queue node
    int size; // Number of elements in queue
public:
    LQueue() { front = rear = new Link(); size = 0; }// Constructor
    ~LQueue() { clear(); delete front; } // Destructor
    void clear() { // Clear queue
        while(front->next != NULL) { // Delete each link node
            rear = front;
            delete rear;
        }
        rear = front;
        size = 0;
    }
    void enqueue(const int& it) { // Put element on rear
        rear->next = new Link(it, NULL);
        rear = rear->next;
        size++;
    }
    int dequeue() { // Remove element from front
        if(size != 0){
            int it = front->next->element; // Store dequeued value
            Link *ltemp = front->next; // Hold dequeued link
            front->next = ltemp->next; // Advance front
            if (rear == ltemp) {rear = front;} // Dequeue last element
            delete ltemp; // Delete link
            size --;
            return it; // Return element value
        }else{
            printf("Queue is empty");
        }
    }
    const int& frontValue() const { // Get front element
        if(size != 0, "Queue is empty");
        return front->next->element;
    }
    virtual int length() const { return size; }
};

// Linked stack implementation
class LStack{
private:
    Link *top; // Pointer to first element
    int size; // Number of elements
public:
    LStack() { top = NULL; size = 0; } // Constructor
    ~LStack() { clear(); } // Destructor
    void clear() { // Reinitialize
        while (top != NULL) { // Delete link nodes
            Link *temp = top;
            top = top->next;
            delete temp;
        }
        size = 0;
    }
    void push(const int& it) { // Put "it" on stack
        top = new Link(it, top);
        size++;
    }
    int pop() { // Remove "it" from stack
        if(top != NULL){
            int it = top->element;
            Link *ltemp = top->next;
            delete top;
            top = ltemp;
            size--;
            return it;
        }else{
            printf("Stack is empty");
        }
    }
    const int& topValue() const { // Return top value
        if(top != 0){
        return top->element;
        }else{
            printf("Stack is empty");
        }
    }
    int length() const { return size; } // Return length
};

int main(){
    LQueue *Fila = new LQueue;
    LStack *Estacionamento = new LStack;
    int n,i,j,cam;
    while(cin >> n && n!=0){
        int flag=1,flag3=0;
        for(i=0;i<n;i++){
            cin >> cam;
            Fila->enqueue(cam);
        }
        
        while(Fila->length()!=0){
            int flag2=0;
            if(Fila->length()!=0){
                if(Fila->frontValue()==flag){
                    Fila->dequeue();
                    flag++;
                }
                else{
                    flag2++;
                }
            }else{flag2++;}
            if(Estacionamento->length()!=0){
                if(Estacionamento->topValue()==flag){
                    Estacionamento->pop();
                    flag++;
                }
                else{
                    flag2++;
                }
            }else{flag2++;}
            if(flag2==2){
                Estacionamento->push(Fila->frontValue());
                Fila->dequeue();
            }
        }
        if(Estacionamento->length()>0){
            while(Estacionamento->length()>0){
                if(Estacionamento->topValue()==flag){
                    flag++;
                    Estacionamento->pop();
                }else{
                    for(i=0;i<Estacionamento->length();i++){
                        Estacionamento->pop();
                    }
                }
            }
        }
        // if(Fila->length()>0){
        //     cout << "Fila: ";
        //     for(i=0;i<Fila->length();i++){
        //         printf("%d ",Fila->frontValue());
        //         if(Fila->length()>0){
        //             Fila->dequeue();
        //         }
        //     }
        //     cout << endl;
        // }
        // if(Estacionamento->length()>0){
        //     cout << "Stack: "; 
        //     for(i=0;i<Estacionamento->length();i++){
        //         printf("%d ",Estacionamento->topValue());
        //         if(Estacionamento->length()>0){
        //             Fila->dequeue();
        //         }
        //     }
        //     cout << endl;
        // }
        
        if(flag==n+1){
            printf("yes\n");
        }else{
            printf("no\n");
        }
        
    }
}