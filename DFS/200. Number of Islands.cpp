/*
author: ypz
*/

class Solution {
public:
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& m, int i, int j) {
        if(m[i][j] == true || grid[i][j] == '0')
            return;
        m[i][j] = true;
        if(i < grid.size() - 1) 
            dfs(grid, m, i+1, j);
        if(j < grid[0].size() - 1)
            dfs(grid, m, i, j+1);
        if(i > 0)
            dfs(grid, m, i-1, j);
        if(j > 0)
            dfs(grid, m, i, j-1);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0)
            return 0;
        if(grid[0].size() == 0)
            return 0;
        int ans = 0;
        vector<vector<bool>> m(grid.size(), vector<bool>(grid[0].size(), false));
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(m[i][j] == true || grid[i][j] == '0')
                    continue;
                ans++;
                dfs(grid, m, i, j);
            }
        }
        return ans;
    }
};
