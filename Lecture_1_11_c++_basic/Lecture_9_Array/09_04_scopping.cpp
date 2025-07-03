#include<iostream>
using namespace std;

void update(int arr[], int size){
    cout<<"Print function"<<sizeof(arr)<<endl;
    //updating array
    arr[2]=120;
    for (int  i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl<<"goint back to main function"<<endl;
    
}
int main(){
int arr[3]={3,5,7};
update(arr,3);
cout<<"Printing main function"<<sizeof(arr)<<endl;
for(int i=0; i<3; i++){
    cout<<arr[i]<<" ";
}
return 0;
}