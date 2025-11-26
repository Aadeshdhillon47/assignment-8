#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int v){ data=v; left=right=0; }
};

Node* insert(Node* r,int v){
    if(!r) return new Node(v);
    if(v<r->data) r->left=insert(r->left,v);
    else if(v>r->data) r->right=insert(r->right,v);
    return r;
}

Node* searchRec(Node* r,int key){
    if(!r||r->data==key) return r;
    if(key<r->data) return searchRec(r->left,key);
    return searchRec(r->right,key);
}

Node* searchIter(Node* r,int key){
    while(r){
        if(r->data==key) return r;
        if(key<r->data) r=r->left;
        else r=r->right;
    }
    return 0;
}

Node* findMin(Node* r){
    while(r&&r->left) r=r->left;
    return r;
}

Node* findMax(Node* r){
    while(r&&r->right) r=r->right;
    return r;
}

Node* inorderSuccessor(Node* root,int key){
    Node* succ=0;
    Node* cur=root;
    while(cur){
        if(key<cur->data){ succ=cur; cur=cur->left; }
        else if(key>cur->data) cur=cur->right;
        else{
            if(cur->right) return findMin(cur->right);
            break;
        }
    }
    return succ;
}

Node* inorderPredecessor(Node* root,int key){
    Node* pred=0;
    Node* cur=root;
    while(cur){
        if(key>cur->data){ pred=cur; cur=cur->right; }
        else if(key<cur->data) cur=cur->left;
        else{
            if(cur->left) return findMax(cur->left);
            break;
        }
    }
    return pred;
}

int main(){
    int a[]={20,8,22,4,12,10,14};
    Node* root=0;
    for(int i=0;i<7;i++) root=insert(root,a[i]);

    cout<<(searchRec(root,10)?"RecFound":"RecNotFound")<<"\n";
    cout<<(searchIter(root,100)?"IterFound":"IterNotFound")<<"\n";

    Node*s=inorderSuccessor(root,10);
    Node*p=inorderPredecessor(root,10);
    cout<<(s?s->data:-1)<<"\n";
    cout<<(p?p->data:-1)<<"\n";
}
