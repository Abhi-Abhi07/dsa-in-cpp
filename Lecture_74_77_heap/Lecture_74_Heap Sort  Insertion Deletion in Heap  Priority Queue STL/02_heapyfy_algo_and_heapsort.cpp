#include<iostream>
using namespace std;

// 1 based indexing
// void heapyfy(int arr[], int n, int i){
//     int largest=i;
//     int left=i*2;
//     int right=i*2+1;
//     if(left<=n && arr[largest]<arr[left]){
//         largest=left;
//     }
//     if(right<=n && arr[largest]<arr[right]){
//         largest=right;
//     }
//     if(largest!=i){
//         swap(arr[largest],arr[i]);
//         heapyfy(arr,n,largest);
//     }
// }

// void heapSort(int arr[],int n){
//     int size=n;
//     while(size>1){
//         swap(arr[1],arr[size]);
//         size--;
//         heapyfy(arr,size,1);
//     }
// }

// 0 based indexing
void heapyfy(int arr[], int n, int i){
    int largest=i;
    int left=i*2+1;
    int right=i*2+2;
    if(left<n && arr[largest]<arr[left]){
        largest=left;
    }
    if(right<n && arr[largest]<arr[right]){
        largest=right;
    }
    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapyfy(arr,n,largest);
    }
}

void heapsort(int arr[],int n){
    int size=n;
    while(size>0){
    swap(arr[0],arr[size-1]);
    size--;
    heapyfy(arr,size,0);
    }
}
int main(){
    // 1 based indexing
    // int arr[7]={-1,50,40,60,10,20,70};
    // int n=6;
    // for(int i=n/2; i>0; i--){
    //     heapyfy(arr,n,i);
    // }
    // cout<<"Heapfy complete now printing : "<<endl;
    // for(int i=1; i<=n; i++){
    //     cout<<arr[i]<<" ";
    // }cout<<endl;

    // heapSort(arr,n);
    // cout<<"HeapSort complete now printing : "<<endl;
    // for(int i=1; i<=n; i++){
    //     cout<<arr[i]<<" ";
    // }cout<<endl;


    // 0 based indexing
    // int arr[]={53,60,50,37,38,67,89,34,23,1,2,3,4,5};
    int arr[]={1,4,3,2,5,7,6};

    int n=7;
    for(int i=n/2-1; i>=0; i--){
        heapyfy(arr,n,i);
    }
    cout<<"Now printing : "<<endl;
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    heapsort(arr,n);
    cout<<"After heapsort printing : "<<endl;
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
return 0;
}