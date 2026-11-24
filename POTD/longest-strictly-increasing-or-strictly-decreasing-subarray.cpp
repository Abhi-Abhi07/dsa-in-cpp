// Problem link: https://leetcode.com/problems/longest-strictly-increasing-or-strictly-decreasing-subarray/

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;
        int i = 0;
        while(i+1 < n){
            while(i+1 < n && nums[i] == nums[i+1])   i++;

            int x = i;
            while(i+1 < n && nums[i] < nums[i+1])   i++;
            ans = max(ans, i-x+1);

            x = i;
            while(i+1 < n && nums[i] > nums[i+1])   i++;
            ans = max(ans, i-x+1);
        }
        return ans;
    }
};