#include <iostream>
using namespace std;

struct BSTNode{
    int key,element;
    BSTNode *left, *right;
    BSTNode() : key(0),element(0), left(NULL), right(NULL){}
    BSTNode(int x,int y): key(x),element(y), left(NULL), right(NULL){}
};

class BST{
private:
    BSTNode *root;
    int nodecount;
public:
    BST(){
        root = NULL;
        nodecount = 0;
    }

    BSTNode *Root (){
        return root;
    }
    BSTNode *inserthelp(BSTNode *rt, int k, int e){
        if(rt==NULL){
            BSTNode *NewNode = new BSTNode(k,e);
            return NewNode;
        }
        if(rt->key>k){
            rt->left = inserthelp(rt->left,k,e);
        }else{
            rt->right = inserthelp(rt->right,k,e);
        }
    }
    
    void insert(int k, int e){
        root = inserthelp(root,k,e);
        nodecount++; 
    }

    void postorder(BSTNode *rt){
        if(rt!=NULL){
            postorder(rt->left);
            postorder(rt->right);
            cout << rt->key << endl; 
        }
    }
};

int main(){
    BST *Tree = new BST;
    int n;
    while(cin >> n && !cin.eof()){
        Tree->insert(n, n);
    }
    Tree->postorder(Tree->Root());
}
