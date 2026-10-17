// Problem link : https://leetcode.com/problems/minimum-swaps-to-sort-by-digit-sum/description/

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>arr(n);
        for(int i=0; i<n; i++){
            int sum = 0;
            int num = nums[i];
            while(num){
                sum += num % 10;
                num /= 10;
            }
            arr[i] = {sum,nums[i],i};
        }
        
        sort(arr.begin(), arr.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] != b[0]) {
                return a[0] < b[0]; // Sort by digit sum first
            }
            return a[1] < b[1];     // If digit sums are equal, sort by original value
        });

        // Cycle sort logic to find minimum swaps
        int ans = 0;
        for(int i=0; i<n; i++){
            if(arr[i][2] == i)  continue;

            int x = i;
            int cnt = 0;
            while(arr[x][2] != x){
                int temp = arr[x][2];
                arr[x][2] = x; 
                x = temp;
                cnt++;
            }
            ans += cnt-1;
        }

        return ans;
    }
};