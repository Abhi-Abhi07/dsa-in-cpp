// Problem link: https://leetcode.com/problems/minimum-positive-sum-subarray/

class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int ans = INT_MAX;
        int n = nums.size();
        while(l <= r){
            int sum = 0;
            for(int i=0; i<n; i++){
                sum += nums[i];
                if(i >= l)
                    sum -= nums[i-l];
                
                if(i >= l-1 && sum > 0)
                    ans = min(ans, sum);
            }
            l++;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};