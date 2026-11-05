// Problem link: https://leetcode.com/problems/minimum-moves-to-equal-array-elements/

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int low = ranges::min(nums);
        int moves = 0;
        for (int &n : nums) moves += n - low;
        return moves;
    }
};