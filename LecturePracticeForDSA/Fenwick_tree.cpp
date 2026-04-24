#include<iostream>
#include<vector>
using namespace std;

void updateArr(vector<int>&arr, int i, int val,int n){
    while(i<=n){
        arr[i]+=val;
        i += i&(-i);
    }
}
int getSum(vector<int>&arr, int i){
    int ans=0;
    while(i>0){
        ans+=arr[i];
        i -= i&(-i);
    }
    return ans;
}
int main(){
    vector<int>temp={-1,3,5,2,1,1,3,7,2,1,1,2};
    int n=temp.size();
    vector<int>arr(n+1);
    arr[0]=-1;
    for(int i=1; i<=n; i++){
        updateArr(arr,i,temp[i],n);
    }
    cout<<" ****** "<<endl;
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    // cout<<"updating arr \n";
    // int val;
    // cin>>val;
    // int index;
    // cin>>index;
    // updateArr(arr,index,-temp[index],n);
    // temp[index]=val;
    // updateArr(arr,index,val,n);

    // int l,r;
    // cin>>l>>r;
    // cout<<getSum(arr,r)-getSum(arr,l-1)<<endl;
return 0;
}