// Problem link: https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/

class Solution {
public:
    const int MOD = 1e9 + 7;
    int numOfSubarrays(vector<int>& arr) {
        int even = 1, odd = 0;
        long long ans = 0;
        int sum = 0;
        int n = arr.size();
        for (int i=0; i<n; i++) {
            sum += arr[i];
            if (sum & 1) {
                ans += even;
                odd++;
            } else {
                ans += odd;
                even++;
            }
        }
        return ans % MOD;
    }
};