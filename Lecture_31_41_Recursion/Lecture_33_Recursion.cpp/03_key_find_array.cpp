#include<iostream>
using namespace std;

bool isPresent(int *arr, int n, int key){
    //Base case
    if(n==0){
        return n;
    }
    if(arr[0]==key){
        return 1;
    }
    return isPresent(arr+1,n-1,key);
    
}

int main(){
int arr[]={1,2,3,4,-3,5};
int size=sizeof(arr)/sizeof(arr[0]);
int key;
cout<<"Enter key : ";
cin>>key;
if(isPresent(arr,size,key)){
    cout<<"found"<<endl;
}
else{
    cout<<"Not found"<<endl;
}
return 0;
}