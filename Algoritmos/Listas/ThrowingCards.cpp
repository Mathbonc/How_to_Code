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

//Implementando Lista//
class LList{
	private:
	    Link *head; //Header
	    Link *tail; //Last Man Standing
	    Link *curr; //Curr
	    int count;  //Size

	    void init(){
	        curr = tail = head = new Link;
	        count = 0;
	    }

	    void removeall(){
	        while(head != NULL){
	            curr = head;
	            head = head->next;
	            delete curr;
	        }
	    }
	public:
	    LList(){ init();} //Construtor
	    ~LList(){ removeall();} //Desconstrutor
	    void print() const;
	    void clear(){
	        removeall();
	        init();
	    }
	    //Colocar "it" na curr
	    void insert (const int& it){
	        curr->next = new Link(it, curr->next);
	        if(tail == curr){
	            tail = curr->next;//NEW TAIL
	        }
	        count++;
	    }
	    void append(const int& it){ //Adiciona "it" à lista
	        tail = tail->next = new Link(it, NULL);
	        count++;
	    }

	    int remove(){
	        if(curr->next != NULL){
	            int it = curr->next->element;
	            Link *ltemp = curr->next;
	            if(tail == curr->next){
	                tail = curr;
	            }
                curr->next = curr->next->next;
                delete ltemp;
                count--;
                return it;
	        }
            else{
                cout << "No element." << endl;
            }
	    }

	    void moveToStart(){
	        curr = head;
	    }
	    void moveToEnd(){
	        curr = tail;
	    }
	    void prev(){
	        if(curr == head)return;
	        Link *temp = head;
	        while (temp->next != curr) temp = temp->next;
	        curr = temp;
	    }
	    void next(){
	        if(curr != tail) curr = curr->next;
	    }
	    int length() const{ return count;}
	    int currPos() const {
	        Link *temp = head;
	        int i;
	        for (i = 0; curr != temp; i++){
	            temp = temp->next;
	        }
	        return i;
	    }
	    void moveToPos(int pos){
	        if((pos >= 0) && (pos <= count)){
	            curr = head;
	            for(int i = 0; i < pos; i++){
	                curr = curr->next;
	            }
	        }
	        else{
	            cout << "Position out of range." << endl;
	        }
	    }
	    const int& getValue() const {
	        if(curr->next != NULL){
	            return curr->next->element;
	        }
	        else{
	            cout << "No value." << endl;
	        }
	    }
        void finish(){
            removeall();
        }
};

int main(){
    int n, i, j, TempoVar;
    LList *ListaLinkada = new LList;
    
    while(cin >> n && n != 0){
        for(i = 1; i <= n; i++){
            ListaLinkada->insert(i);
        }

        if(ListaLinkada->length() > 1){
            cout << "Discarded cards: ";
        }
        else cout << "Discarded cards:" << endl;

        while(ListaLinkada->length() > 1){
            ListaLinkada->moveToEnd();
            ListaLinkada->prev();
            if(ListaLinkada->length()>2){
                cout << ListaLinkada->getValue() << ", ";
            }
            else{
                cout << ListaLinkada->getValue() << endl;
            }
            ListaLinkada->remove();
            ListaLinkada->prev();
            if(ListaLinkada->length() >= 2){
                TempoVar = ListaLinkada->getValue();
                ListaLinkada->remove();
                ListaLinkada->moveToStart();
                ListaLinkada->insert(TempoVar);
            }
        }
        ListaLinkada->moveToStart();
        cout << "Remaining card: " << ListaLinkada->getValue()<< endl;
        ListaLinkada->remove();
        ListaLinkada->clear();
    }
    ListaLinkada->finish();
    return 0;
}