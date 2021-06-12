/* 
Leetcode 675: Cut Off Trees for Golf Event
*/

class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {
        
        vector<vector<int>> tree; // {height, i, j}
        int i, ans = 0, steps;
        int m = forest.size();
        int n = forest[0].size();
        for(i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(forest[i][j]) {
                     tree.push_back({forest[i][j], i, j});
                }        
            }
        }
        sort(tree.begin(), tree.end());

        int cur_row = 0, cur_col = 0;
        for(i = 0; i < tree.size(); ++i) {
            steps = bfs(forest, cur_row, cur_col, tree[i][1], tree[i][2], m, n);
            if(steps == -1)
                return -1;
            ans += steps;
            cur_row = tree[i][1]; 
            cur_col = tree[i][2];
        }
        return ans;             
    }
             
             
    int bfs(vector<vector<int>> forest, int startRow, int startCol, int destRow, int destCol, int m, int n) {
        if(startRow == destRow && startCol == destCol)
            return 0;
        queue<pair<int, int>> q;
        vector<int> dir = {-1,0,1,0,-1};
        // int m = forest.size(), n = forest[0].size(), i;
        vector<vector<int>> visited(m, vector<int>(n,0));
        int steps = 0, endRow, endCol, i;
        
        q.push({startRow, startCol});

        while(! q.empty()) {
            int len = q.size();
            steps++;
            
            for(i = 0; i < len; ++i) {
                int x = q.front().first;
                int y = q.front().second;
                visited[x][y] = 1;
                q.pop();
                for(int k = 0; k < 4; ++k) {       
                    endRow = x + dir[k];
                    endCol = y + dir[k + 1];
                   if(endRow == destRow && endCol == destCol)
                        return steps;
                    if(endRow < 0 || endRow >= m || endCol < 0 || endCol >= n || visited[endRow][endCol]|| forest[endRow][endCol] == 0)
                        continue;

                    q.push({endRow, endCol});
                }
            }
        }
        return -1;
    }
};
