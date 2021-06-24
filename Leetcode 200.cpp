/*

Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

*/


class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int  row = grid.size();
        int  col = grid[0].size();
        int   count  = 0;
        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j) {
                if(grid[i][j] == '1') {
                     count++;
                     dfs(i,j,grid);
                }
                
            }
        }
        return  count;
    }
    void dfs(int  i, int  j, vector<vector<char>>& grid) {
        int  row = grid.size();
        int  col = grid[0].size();
        int dir[] = {-1, 0, 1, 0, -1};
            grid[i][j] = 2;
            for(int  k = 0; k < 4; ++k) {
                int r = i + dir[k];
                int c = j + dir[k + 1];
                if(r < row && r >= 0 && c < col && c >= 0 && (grid[r][c] == '1'))
                    dfs(r, c, grid);
            }
    }
};
