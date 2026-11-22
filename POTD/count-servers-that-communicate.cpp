// Problem link: https://leetcode.com/problems/count-servers-that-communicate/

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        int ans = 0;
        for(int i=0; i<rows; i++){
            int cnt = 0;
            int col = 0;
            for(int j=0; j<cols; j++){
                if(grid[i][j])  col = j;
                cnt += grid[i][j];
            }
   
            if(cnt == 0)    continue;

            if(cnt >= 2){
                ans += cnt;
            }else{
                int x = 0;
                for(int r=0; r<rows; r++)
                    x += grid[r][col];
                if(x >= 2)  ans++;
            }
        }

        return ans;
    }
};