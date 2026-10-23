// Problem link: https://leetcode.com/problems/maximum-k-to-sort-a-permutation/description/

class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        int x = INT_MAX;
        for(int i=0; i<n; i++)
            if(nums[i] != i)    
                x &= nums[i];
        
        return x == INT_MAX ? 0 : x;
    }
};