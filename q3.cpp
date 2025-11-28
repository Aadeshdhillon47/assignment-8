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

Node* findMin(Node* r){
    while(r&&r->left) r=r->left;
    return r;
}

Node* deleteNode(Node* r,int key){
    if(!r) return 0;
    if(key<r->data) r->left=deleteNode(r->left,key);
    else if(key>r->data) r->right=deleteNode(r->right,key);
    else{
        if(!r->left){ Node*t=r->right; delete r; return t; }
        if(!r->right){ Node*t=r->left; delete r; return t; }
        Node*m=findMin(r->right);
        r->data=m->data;
        r->right=deleteNode(r->right,m->data);
    }
    return r;
}

int maxDepth(Node* r){
    if(!r) return 0;
    int l=maxDepth(r->left);
    int ri=maxDepth(r->right);
    return (l>ri?l:ri)+1;
}

int minDepth(Node* r){
    if(!r) return 0;
    if(!r->left) return minDepth(r->right)+1;
    if(!r->right) return minDepth(r->left)+1;
    int l=minDepth(r->left);
    int ri=minDepth(r->right);
    return (l<ri?l:ri)+1;
}

void inorder(Node* r){
    if(!r) return;
    inorder(r->left);
    cout<<r->data<<" ";
    inorder(r->right);
}

int main(){
    int a[]={15,10,20,8,12,17,25};
    Node* root=0;
    for(int i=0;i<7;i++) root=insert(root,a[i]);

    inorder(root); cout<<"\n";
    root=deleteNode(root,10);
    inorder(root); cout<<"\n";

    cout<<maxDepth(root)<<"\n";
    cout<<minDepth(root)<<"\n";
}
