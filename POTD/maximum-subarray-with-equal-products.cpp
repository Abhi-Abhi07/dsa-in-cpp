// Problem link: https://leetcode.com/problems/maximum-subarray-with-equal-products/

class Solution {
public:
    int findGCD(int a,int b){
        while(b != 0){
            int temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }

    int findLCM(int a,int b){
        return (a / findGCD(a,b)) * b;
    }

    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i=0; i<n; i++){
            int x = nums[i];
            int y = nums[i];
            int p = nums[i];
            for(int j=i+1; j<n; j++){
                if(p > INT_MAX / nums[j]) break;
                p *= nums[j];
                x = findGCD(x,nums[j]);
                y = findLCM(y,nums[j]);

                if(p == (x * y))
                    ans = max(ans, j-i+1);
            }
        }
        return ans;
    }
};