/*
Problem link : https://leetcode.com/problems/find-target-indices-after-sorting-array/description/
*/

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int st = lower_bound(nums.begin(),nums.end(),target) - nums.begin();
        int ed = upper_bound(nums.begin(),nums.end(),target) - nums.begin();
        vector<int> ans(ed - st);
        iota(ans.begin(), ans.end(), st);
        return ans;
    }
};