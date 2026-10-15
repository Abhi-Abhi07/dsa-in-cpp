/*
Problem link - https://leetcode.com/problems/subarrays-distinct-element-sum-of-squares-i/
*/

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int i=0; i<n; ++i){
            int x = 0;
            vector<bool>vis(100+1,false);
            for(int j=i; j<n; ++j){
                if(!vis[nums[j]]){
                    vis[nums[j]] = true;
                    x++;
                } 
                sum += (x * x);
            }
        }
        return sum;
    }
};