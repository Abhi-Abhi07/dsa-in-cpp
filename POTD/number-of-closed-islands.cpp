// problem link : https://leetcode.com/problems/number-of-closed-islands/description/

class Solution {
public:
    bool dfs(int r,int c,int &rows,int &cols,vector<vector<int>>& grid){
        // out of bound
        if((r<0 || r>=rows) || (c<0 || c>=cols)) return false;

        // curr side water so return true
        if(grid[r][c] == 1) return true;

        // mark visted
        grid[r][c] = 1;

        // get res from all direction
        bool down = dfs(r+1,c,rows,cols,grid);
        bool left = dfs(r,c-1,rows,cols,grid);
        bool right = dfs(r,c+1,rows,cols,grid);
        bool up = dfs(r-1,c,rows,cols,grid);

        // if all the direction water then true else false
        return down && left && right && up;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int cnt = 0;
        for(int r=0; r<rows; r++){
            for(int c=0; c<cols; c++){
                if(grid[r][c] == 0){
                    bool isClosed = dfs(r,c,rows,cols,grid);
                    cnt = (isClosed == true ? cnt + 1 : cnt);
                }
            }
        }
        return cnt;
    }
};