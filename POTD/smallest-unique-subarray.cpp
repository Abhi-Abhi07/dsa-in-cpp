// Problem link: https://leetcode.com/problems/smallest-unique-subarray/

class Solution {
public:
    const int MOD = 1e9 + 7;
    typedef long long ll;
    ll getPower(int a, int b){
        ll ans = 1;
        while(b){
            if(b & 1) ans = (ans * a) % MOD;
            a = (1LL * a * a) % MOD;
            b >>= 1;
        }
        return ans;
    }
    bool check(int &base,int &len,vector<int>& nums){
        unordered_map<int,int> mp;
        ll p = getPower(base, len-1);
        ll hash = 0;
        for(int i=0, j=0; j<nums.size(); j++){
            hash = (hash * base + nums[j]) % MOD;
            if(j - i + 1 >= len){
                mp[hash]++;
                hash = (hash - ((p * nums[i++]) % MOD) + MOD) % MOD;
            }
        }

        for (const pair<const int, int>& it : mp)
            if(it.second == 1)  
                return true;
        
        return false;
    }
    int smallestUniqueSubarray(vector<int>& nums) {
        int l = 1;
        int r = nums.size();
        int base = *max_element(begin(nums),end(nums)) + 1;
        int ans = 1;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(check(base,mid,nums)){
                ans = mid;
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        return ans;
    }
};