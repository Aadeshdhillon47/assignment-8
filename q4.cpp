#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int v){ data=v; left=right=0; }
};

bool isBST(Node* r,int minv,int maxv){
    if(!r) return true;
    if(r->data<=minv||r->data>=maxv) return false;
    return isBST(r->left,minv,r->data)&&isBST(r->right,r->data,maxv);
}

int main(){
    Node* root=new Node(10);
    root->left=new Node(5);
    root->right=new Node(15);

    cout<<(isBST(root,-2147483648,2147483647)?"Yes":"No")<<"\n";

    Node* root2=new Node(10);
    root2->left=new Node(20);
    root2->right=new Node(5);

    cout<<(isBST(root2,-2147483648,2147483647)?"Yes":"No")<<"\n";
}
