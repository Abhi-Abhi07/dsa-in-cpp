/*
Problem link : https://leetcode.com/problems/number-of-ways-to-reorder-array-to-get-same-bst/description/
*/

class Solution {
public:
    int MOD = 1e9 + 7;
    typedef long long ll;

    // pascal triangle for nCr calculation
    vector<vector<ll>>PT;

    ll solve(vector<int> nums){
        int n = nums.size();
        if(n < 3)    
            return 1;

        vector<int>leftArr;
        vector<int> rightArr;
        for(int i=1; i<n; i++){
            if(nums[i] < nums[0])
                leftArr.push_back(nums[i]);
            else
                rightArr.push_back(nums[i]);
        }

        ll l = solve(leftArr);
        ll r = solve(rightArr);

        // nCr
        // n = n-1
        // r = leftArr.size();
        ll k = PT[n-1][leftArr.size()];

        return (((l*r) % MOD) * k) % MOD;
    }
    int numOfWays(vector<int>& nums) {
        int n = nums.size();

        // pascal Triangle table filling
        PT.resize(n+1);
        for(int i=0; i<=n; i++){
            PT[i] = vector<ll>(i+1, 1);
            for(int j=1; j<i; j++){
                PT[i][j] = (PT[i-1][j-1] + PT[i-1][j]) % MOD;
            }
        }
        
        ll ans = solve(nums);
        return ans - 1;
    }
};