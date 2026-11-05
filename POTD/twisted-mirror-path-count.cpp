// problem link: https://leetcode.com/problems/twisted-mirror-path-count/description/

class Solution {
public:
    int n, m;
    long long int mod = 1e9 + 7;
    vector<vector<vector<long long int>>> dp;
    long long int solve(int i, int j, int dir, vector<vector<int>>& nums) {
        if(i >= n || j >= m)    return 0;
        if(i == n-1 && j == m-1)    return 1;
        
        if(dp[i][j][dir] != -1)
            return dp[i][j][dir];
        
        if(nums[i][j] == 1){
            if(dir == 0)
                dp[i][j][dir] = solve(i+1, j, 1, nums);
            else
                dp[i][j][dir] = solve(i, j+1, 0, nums);
        }else{
            dp[i][j][dir] = (solve(i, j+1, 0, nums) + solve(i+1, j, 1, nums)) % mod;
        }
        return dp[i][j][dir];
    }

    int uniquePaths(vector<vector<int>>& nums) {
        n = nums.size(), m = nums[0].size();
        dp.assign(n, vector<vector<long long int>>(m, {-1, -1}));
        return solve(0, 0, 0, nums);
    }
};