// Problem link: https://leetcode.com/problems/minimum-operations-to-make-elements-within-k-subarrays-equal/

class Solution {
public:
    using ll = long long;
    multiset<ll> left, right;
    ll left_sum = 0, right_sum = 0;

    void addElement(ll val){
        if(left.empty() || val <= *left.rbegin()){
            left.insert(val);
            left_sum += val;
        }else{
            right.insert(val);
            right_sum += val;
        }
    }

    void removeElement(ll val){
        auto it = left.find(val);
        if(it != left.end()){
            left.erase(it);
            left_sum -= val;
        }else{
            right.erase(right.find(val));
            right_sum -= val;
        }
    }

    void balance(){
        while(left.size() > right.size() + 1){
            ll val = *left.rbegin();
            left.erase(prev(left.end()));
            left_sum -= val;
            right.insert(val);
            right_sum += val; 
        }

        while (left.size() < right.size()) {
            ll val = *right.begin();
            right.erase(right.begin());
            right_sum -= val;
            left.insert(val);
            left_sum += val;
        }
    }

    ll solve(int i,int &n,int &x,int k,vector<ll> &cost, vector<vector<ll>> &dp){
        if(k == 0)  return 0;
        if(i > n - x)   return 1e18;

        if(dp[i][k] != -1) return dp[i][k];

        ll skip = solve(i + 1, n, x, k, cost, dp);
        ll take = cost[i] + solve(i + x, n, x, k - 1, cost, dp);

        return dp[i][k] = min(skip, take);
    }

    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        left.clear();
        right.clear();
        vector<ll>cost(n-x+1,0);
        for(int i=0; i<n; i++){
            addElement(nums[i]);
            balance();
            if(i >= x){
                removeElement(nums[i-x]);
                balance();
            }

            if(i-x+1 >= 0){
                // int totalLeftElem = left.size();
                // int totalRightElem = right.size();
                int median = *left.rbegin();
                cost[i-x+1] = ((median * left.size()) - left_sum) + (right_sum - (median * right.size()));
            }
        }

        vector<vector<ll>>dp(n,vector<ll>(k+1,-1));
        return solve(0,n,x,k,cost,dp);
    }
};