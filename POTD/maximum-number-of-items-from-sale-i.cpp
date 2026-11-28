Problem link: https://leetcode.com/problems/maximum-number-of-items-from-sale-i/

class Solution {
public:
    vector<int> factor_divide_cnt;
    vector<vector<array<int, 2>>> memo;
    void doPreComputeFactorsDivides(vector<vector<int>>& items,int &n){
        factor_divide_cnt.assign(n,0);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i == j)  continue;
                if(items[i][0] <= items[j][0] && ((items[j][0] % items[i][0]) == 0))
                    factor_divide_cnt[i]++;
            }
        }
    }
    
    int solve(int i,int &n,vector<vector<int>> &items, int budget, bool bought){
        if(i >= n)  return 0;
        if(memo[i][budget][bought] != -1)
            return memo[i][budget][bought];

        int skip = solve(i+1,n,items,budget,false);

        int buy = 0;
        if(items[i][1] <= budget){
            buy = bought ? 0 : factor_divide_cnt[i];
            buy += 1 + solve(i,n,items,budget - items[i][1],true);
        }

        return memo[i][budget][bought] = max(buy,skip);
    }

    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        doPreComputeFactorsDivides(items,n);
        // memo.assign(n,vector<array<int, 2>>(budget+1,{-1, -1}));
        // return solve(0,n,items,budget,false);

        memo.assign(n+1,vector<array<int, 2>>(budget+1,{-1, -1}));
        for(int i=n-1; i>=0; --i){
            for(int b=0; b<=budget; ++b){
                for(int bought=1; bought>=0; --bought){
                    int skip = memo[i+1][b][0];

                    int buy = 0;
                    if(items[i][1] <= b){
                        buy = bought ? 0 : factor_divide_cnt[i];
                        buy += 1 + memo[i][b - items[i][1]][1];
                    }

                    memo[i][b][bought] = max(buy,skip);
                }
            }
        }
        return memo[0][budget][0];
    }
};