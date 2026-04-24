#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

class XORBasis{
    public:
    int *basis;
    int size;
    XORBasis(){
        size = 32;
        basis=new int[size];
    }
    void clear(){
        fill_n(basis,size,0);
    }
    void insert(int x){
        for(int i=size-1; i>=0; i--){
            if((x>>i)&1){
                if(basis[i]==0){
                    basis[i]=x;
                    return;
                }
                x^=basis[i];
            }
        }
    }
    int maxXORSubset(){
        int maxXor=0;
        for(int i=size-1; i>=0; i--){
            maxXor=max(maxXor, maxXor ^ basis[i]);
        }
        return maxXor;
    }
};

void preCompute(vector<int>&xorof, vector<int>&andof,int &total,int n,vector<int>&nums){
    for(int i=0; i<n; i++){
        int bit=(1<<i);
        xorof[bit]=nums[i];
        andof[bit]=nums[i];
    }

    for(int mask=1; mask<total; mask++){
        int lowbit = mask & -mask;
        if(lowbit == mask)  continue;
        int pre = lowbit ^ mask;
        xorof[mask]=xorof[lowbit]^xorof[pre];
        andof[mask]=andof[lowbit]&andof[pre];
    }
}

long long maximizeXorAndXor(vector<int>& nums) {
    int n=nums.size();
    int total=(1<<n);

    vector<int>andof(total,0);
    vector<int>xorof(total,0);
    preCompute(xorof,andof,total,n,nums);

    XORBasis basis;
    vector<int>resXor(total,0);
    for(int mask=1; mask<total; mask++){
        basis.clear();
        int maskXor = xorof[mask];

        for(int i=0; i<n; i++){
            int bit = 1<<i;
            if(mask & bit){
                basis.insert(nums[i] & (~maskXor));
            }
        }
        resXor[mask] = xorof[mask] + 2*basis.maxXORSubset();
    }

    long long res=LLONG_MIN;
    for(int mask=0; mask<total; mask++){
        int complement = (total-1) ^ mask;
        res = max(res, 1LL*(resXor[mask]+andof[complement]));
    }
    return res;
}
int main() {

    vector<int>nums = {2,3,6,7};
    long long res = maximizeXorAndXor(nums);
    cout<<"final ans is : "<<res<<endl;
    
    return 0;

}