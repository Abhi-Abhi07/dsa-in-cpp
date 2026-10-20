/*
Problem link:https://leetcode.com/problems/sum-of-sortable-integers

*/

class Solution {
public:
    bool checkBlockIsSortableOrNot(int &k,int &n,vector<int> &nums){
        int maxOfPrevBlock = 0;
        for(int i=0; i<n; i+=k){
            if(maxOfPrevBlock > nums[i])    
                return false;

            int maxOfCurrBlock = nums[i];
            int breakAblePoints = 0;
            for(int j=i+1; j<i+k; j++){
                if(maxOfPrevBlock > nums[j])
                    return false;

                if(nums[j-1] > nums[j] && ++breakAblePoints > 1)
                    return false;
                
                maxOfCurrBlock = max(nums[j],maxOfCurrBlock);
            }
            if(breakAblePoints == 1 && nums[i] < nums[i+k-1])
                return false;

            maxOfPrevBlock = maxOfCurrBlock;
        }
        return true;
    }
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        for(int k=1; k<=n; k++){
            if(n % k != 0)  continue;
            if(checkBlockIsSortableOrNot(k,n,nums)) res += k;
        }
        return res;
    }
};