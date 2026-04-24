#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int i=2;
    bool isPrime=true;
    while(i<n){
        if(n%i==0){
            isPrime=false;
        }
    i=i+1;
    }
    if(isPrime){
        cout<<"prime"<<endl;
    }else{
        cout<<"not prime"<<endl;
    }
    return 0;
}