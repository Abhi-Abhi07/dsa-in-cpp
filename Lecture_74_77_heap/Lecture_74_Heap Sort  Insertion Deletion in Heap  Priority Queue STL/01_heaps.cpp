#include<iostream>
using namespace std;

class heap{
    public:
    int arr[100];
    int size;
    heap(){
        arr[0]=-1;
        size=0;
    }
    void insertMaxHeap(int value){
        size++;
        int index=size;
        arr[index]=value;
        while(index>1){
            int parent=index/2;
            if(arr[parent]<arr[index]){
                swap(arr[index],arr[parent]);
                index=parent;
            }
            else{
                return ;
            }
        }
    }
    void deletionInMaxHeap(){
        // cout<<"  **size**  "<<size<<endl;
        if(size==0){
            cout<<"Nothing to delete"<<endl;
            return;
        }
        arr[1]=arr[size];
        size=size-1;
        int index=1;
        while(index<=size/2){
            int leftIndex=index*2;
            int rightIndex=index*2+1;
            if(rightIndex<=size && arr[leftIndex]<arr[rightIndex] && arr[rightIndex]>arr[index]){
                swap(arr[index],arr[rightIndex]);
                index=rightIndex;
            }
            else if(arr[leftIndex]>arr[index]){
                swap(arr[leftIndex],arr[index]);
                index=leftIndex;
            }
            else{
                return;
            }
        }
    }
    void insertMinHeap(int value){
        size++;
        int index=size;
        arr[index]=value;
        while(index>1){
            int parent=index/2;
            if(arr[parent]>arr[index]){
                swap(arr[index],arr[parent]);
                index=parent;
            }
            else{
                return ;
            }
        }
    }
    void deletionInMinHeap(){
        if(size==0){
            cout<<"Nothing to delete"<<endl;
            return;
        }
        arr[1]=arr[size];
        size=size-1;
        int index=1;
        while(index<=size/2){
            int child=index*2;
            if(child<=size && arr[child]<arr[index]){
                swap(arr[index],arr[child]);
                index=child;
            }
            else if(child+1<=size && arr[child+1]<arr[index]){
                swap(arr[child+1],arr[index]);
                index=child+1;
            }
            else{
                return;
            }
        }
    }
    void print(){
        for(int i=1; i<=size; i++){
            cout<<arr[i]<<" ";
        }cout<<endl;
    }
};


int main(){
    heap h;
    h.insertMaxHeap(34);
    h.insertMaxHeap(10);
    h.insertMaxHeap(12);
    h.insertMaxHeap(25);
    h.insertMaxHeap(5);
    h.insertMaxHeap(33);
    h.insertMaxHeap(40);
    // h.deletionInMaxHeap();
    // h.deletionInMaxHeap();
    // h.deletionInMaxHeap();
    // h.deletionInMaxHeap();
    // h.deletionInMaxHeap();
    // h.deletionInMaxHeap();
    // h.deletionInMaxHeap();
    // h.deletionInMaxHeap();


    // h.insertMinHeap(34);
    // h.insertMinHeap(10);
    // h.insertMinHeap(12);
    // h.insertMinHeap(25);
    // h.insertMinHeap(5);
    // h.insertMinHeap(33);
    // h.insertMinHeap(40);
    // h.deletionInMinHeap();
    // h.deletionInMinHeap();
    // h.deletionInMinHeap();
    
    h.print();


return 0;
}