// problem link : https://leetcode.com/problems/count-islands-with-total-value-divisible-by-k/

class Solution {
public:
    void dfs(int r,int c,int &rows,int &cols,vector<vector<int>>& grid, long long &x){
        if(r<0 || r>=rows || c<0 || c>=cols || grid[r][c] == 0) return;

        // mark visted
        x += grid[r][c];
        grid[r][c] = 0;

        dfs(r+1,c,rows,cols,grid,x);
        dfs(r,c-1,rows,cols,grid,x);
        dfs(r,c+1,rows,cols,grid,x);
        dfs(r-1,c,rows,cols,grid,x);
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        int cols = grid[0].size();
        int cnt = 0;
        for(int r=0; r<rows; r++){
            for(int c=0; c<cols; c++){
                if(grid[r][c] == 0) continue;
                long long x = 0;
                dfs(r,c,rows,cols,grid,x);
                if(x % k == 0)  cnt++;
            }
        }
        return cnt;
    }
};