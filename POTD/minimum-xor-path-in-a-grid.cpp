// problem link : https://leetcode.com/problems/minimum-xor-path-in-a-grid/description/

class Solution {
public:
    vector<vector<vector<int>>>dp;
    int solve(int r,int c,int curr_xor,int &rows,int &cols,vector<vector<int>>& grid){
        if(r >= rows || c >= cols)  return 1e7;

        curr_xor ^= grid[r][c];
        if(r == rows-1 && c == cols-1)  return curr_xor;

        if(dp[r][c][curr_xor] != -1)  return dp[r][c][curr_xor];

        int right = solve(r,c+1,curr_xor,rows,cols,grid);
        int down = solve(r+1,c,curr_xor,rows,cols,grid);

        return dp[r][c][curr_xor] = min(right,down);
    }
    int minCost(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        dp.assign(rows,vector<vector<int>>(cols,vector<int>(1024,-1)));

        return solve(0,0,0,rows,cols,grid);
    }
};