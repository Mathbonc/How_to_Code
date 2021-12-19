#include <iostream>
using namespace std;


class BSTNode{
private:
    int element;
    BSTNode *left;
    BSTNode *right;
public:
    BSTNode(){
        left = right = NULL;
    }
    BSTNode(int E, BSTNode *l = NULL, BSTNode *r = NULL){
        element = E;
        left = l;
        right = r;
    }
    ~BSTNode(){

    }
    int& Element(){
        return element;
    }
    void setElement(const int& E){
        element = E;
    }
    
    BSTNode* Left(){ 
        return left; 
    }
    void setLeft(BSTNode *b) { 
        left = b; 
    }
    BSTNode* Right(){ 
        return right; 
    }
    void setRight(BSTNode *b) { 
        right = b;
    }

};

class BST{
private:
    BSTNode *root;
    int nodecount;

    BSTNode* insertHelp(BSTNode*, int);
    void clearHelp(BSTNode*);
public:
    BST(){
        root = NULL;
        nodecount = 0;
    }

    ~BST(){
        clearHelp(root);
    }

    void clear(){
        clearHelp(root);
        root = NULL;
        nodecount=0;
    }

    BSTNode *Root (){
        return root;
    }
    
    void insert(int e){
        root = insertHelp(root,e);
        nodecount++; 
    }
    
    void postorder(BSTNode* rt){
        if(rt!=NULL){
            postorder(rt->Left());
            postorder(rt->Right());
            cout << rt->Element() << endl; 
        }
    }
};

void BST::clearHelp(BSTNode* Node){
    if(Node == NULL){
        return;
    }
    clearHelp(Node->Left());
    clearHelp(Node->Right());
    delete Node;
}
BSTNode* BST::insertHelp(BSTNode *rt, int e){
    if(rt==NULL){
        return new BSTNode(e, NULL, NULL);
    }
    if(e < rt->Element()){
        rt->setLeft(insertHelp(rt->Left(), e));
    }else{
        rt->setRight(insertHelp(rt->Right(),e));
    }
    return rt;
}

int main(){
    BST *Tree = new BST;
    int n;
    while(cin >> n){
        Tree->insert(n);
    }
    Tree->postorder(Tree->Root());
    delete Tree;
}
