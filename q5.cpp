#include <iostream>
using namespace std;

void heapifyMax(int a[],int n,int i){
    int largest=i;
    int l=2*i+1;
    int r=2*i+2;
    if(l<n&&a[l]>a[largest]) largest=l;
    if(r<n&&a[r]>a[largest]) largest=r;
    if(largest!=i){
        int t=a[i]; a[i]=a[largest]; a[largest]=t;
        heapifyMax(a,n,largest);
    }
}

void heapifyMin(int a[],int n,int i){
    int smallest=i;
    int l=2*i+1;
    int r=2*i+2;
    if(l<n&&a[l]<a[smallest]) smallest=l;
    if(r<n&&a[r]<a[smallest]) smallest=r;
    if(smallest!=i){
        int t=a[i]; a[i]=a[smallest]; a[smallest]=t;
        heapifyMin(a,n,smallest);
    }
}

void heapsortInc(int a[],int n){
    for(int i=n/2-1;i>=0;i--) heapifyMax(a,n,i);
    for(int i=n-1;i>=1;i--){
        int t=a[0]; a[0]=a[i]; a[i]=t;
        heapifyMax(a,i,0);
    }
}

void heapsortDec(int a[],int n){
    for(int i=n/2-1;i>=0;i--) heapifyMin(a,n,i);
    for(int i=n-1;i>=1;i--){
        int t=a[0]; a[0]=a[i]; a[i]=t;
        heapifyMin(a,i,0);
    }
}

int main(){
    int a[]={4,10,3,5,1};
    int b[]={4,10,3,5,1};
    int n=5;

    heapsortInc(a,n);
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<"\n";

    heapsortDec(b,n);
    for(int i=0;i<n;i++) cout<<b[i]<<" ";
    cout<<"\n";
}
