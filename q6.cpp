#include <iostream>
using namespace std;

struct MaxHeap{
    int a[100];
    int size;
    MaxHeap(){ size=0; }

    void insert(int v){
        a[size]=v;
        int i=size;
        size++;
        while(i>0&&a[(i-1)/2]<a[i]){
            int t=a[i]; a[i]=a[(i-1)/2]; a[(i-1)/2]=t;
            i=(i-1)/2;
        }
    }

    int extractMax(){
        if(size==0) return -1;
        int root=a[0];
        a[0]=a[size-1];
        size--;
        int i=0;
        while(true){
            int l=2*i+1;
            int r=2*i+2;
            int largest=i;
            if(l<size&&a[l]>a[largest]) largest=l;
            if(r<size&&a[r]>a[largest]) largest=r;
            if(largest==i) break;
            int t=a[i]; a[i]=a[largest]; a[largest]=t;
            i=largest;
        }
        return root;
    }
};

int main(){
    MaxHeap h;
    h.insert(10);
    h.insert(4);
    h.insert(25);
    cout<<h.extractMax()<<"\n";
    cout<<h.extractMax()<<"\n";
    cout<<h.extractMax()<<"\n";
}
