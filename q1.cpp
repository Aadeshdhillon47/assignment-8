#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int v){ data=v; left=right=0; }
};

void preorder(Node* r){
    if(!r) return;
    cout<<r->data<<" ";
    preorder(r->left);
    preorder(r->right);
}

void inorder(Node* r){
    if(!r) return;
    inorder(r->left);
    cout<<r->data<<" ";
    inorder(r->right);
}

void postorder(Node* r){
    if(!r) return;
    postorder(r->left);
    postorder(r->right);
    cout<<r->data<<" ";
}

int main(){
    Node* root=new Node(8);
    root->left=new Node(3);
    root->right=new Node(10);

    cout<<"Pre: "; preorder(root); cout<<"\n";
    cout<<"In: "; inorder(root); cout<<"\n";
    cout<<"Post: "; postorder(root); cout<<"\n";
}
