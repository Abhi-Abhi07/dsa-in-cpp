// Problem link: https://leetcode.com/problems/climbing-stairs-ii/

class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        int one = 0;
        int two = costs[0] + 1;
        int three = n > 1 ? min(two + costs[1] + 1, costs[1] + 4) : two;
        for(int i=2; i<n; i++){
            int curr = min({one+9,two+4,three+1}) + costs[i];
            one = two;
            two = three;
            three = curr;
        }
        return three;
    }
};