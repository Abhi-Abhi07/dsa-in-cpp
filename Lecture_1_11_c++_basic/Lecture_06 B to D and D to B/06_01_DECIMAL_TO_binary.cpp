// #include<iostream>
// #include<bitset>
// #include<numeric>
// using namespace std;

// int main(){
// int n=-123;
// bitset<32>a(n);
// cout<<"\n"<<n<<" : "<<a<<endl;

// n=123;
// bitset<32>x(n);
// cout<<"\n"<<n<<" : "<<x<<endl;
// return 0;
// }



#include<iostream>
#include<numeric>
using namespace std;

int main(){
int n;
cin>>n;
int ans=0;
int i=1,bit;
while(n!=0){
    bit=n&1;
    ans = (bit *i)+ans;

    n=n>>1; // n=n/2; // also use this
    
    i*=10;
}
cout<<"Answer is "<<ans<<endl;

return 0;
}
