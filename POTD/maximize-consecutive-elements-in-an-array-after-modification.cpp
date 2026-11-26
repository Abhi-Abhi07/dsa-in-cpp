// Problem link: https://leetcode.com/problems/maximize-consecutive-elements-in-an-array-after-modification/

class Solution {
public:
    vector<vector<int>> memo;
    int solve(int i,int &n,int inc,vector<int>& nums){
        if(memo[i][inc] != -1)
            return memo[i][inc];

        int curr_value = nums[i] + inc;
        int len = 1;

        // option 1: find curr_value and increment it by 1
        int idx = lower_bound(begin(nums)+i+1,end(nums),curr_value) - begin(nums);
        if(idx < n && nums[idx] == curr_value)
            len = max(len, 1 + solve(idx,n,1,nums));

        // option 2: find next value directly
        idx = lower_bound(begin(nums)+i+1,end(nums),curr_value + 1) - begin(nums);
        if(idx < n && nums[idx] == curr_value + 1)
            len = max(len, 1 + solve(idx,n,0,nums));

        return memo[i][inc] = len;
    }
    int maxSelectedElements(vector<int>& nums) {
        sort(begin(nums),end(nums));
        int n = nums.size();
        int ans = 0;
        memo.assign(n,vector<int>(2,-1));
        for(int i=0; i<n; i++)
            ans = max({ans, solve(i,n,0,nums), solve(i,n,1,nums)});
        
        return ans;
    }
};