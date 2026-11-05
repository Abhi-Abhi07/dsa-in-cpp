// Problem link: https://leetcode.com/problems/minimum-moves-to-equal-array-elements-iii/

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxi = ranges::max(nums);
        int moves = 0;
        for(int &x: nums) 
            moves += maxi - x;
        return moves;
    }
};