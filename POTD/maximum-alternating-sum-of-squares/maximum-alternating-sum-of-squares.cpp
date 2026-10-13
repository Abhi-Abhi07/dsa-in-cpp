/*
Problem link - https://leetcode.com/problems/maximum-alternating-sum-of-squares/description/
*/

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i++)
            nums[i] = abs(nums[i]);
        
        sort(nums.rbegin(),nums.rend());
        long long ans = 0;
        int l = 0, r = n-1;
        while(l < r)
            ans += (1LL * nums[l] * nums[l++]) - (1LL * nums[r] * nums[r--]);

        if(l == r)
            ans += (1LL * nums[l] * nums[l]);

        return ans;
    }
};