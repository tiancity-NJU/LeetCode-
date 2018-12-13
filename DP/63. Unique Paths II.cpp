/*
动态规划，若当前不是障碍物，则ans[i][j] = ans[i-1][j] + ans[i][j-1]；若当前是障碍物，则ans[i][i] = 0.
author: ypz
*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if(m == 0) return 0;
        int n = obstacleGrid[0].size();
        vector<vector<int>> ans(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++) {
            ans[i][0] = 1;
            if(obstacleGrid[i][0] == 1) {
                ans[i][0] = 0;
                break;
            }
        }
        for(int i = 0; i < n; i++) {
            ans[0][i] = 1;
            if(obstacleGrid[0][i] == 1) {
                ans[0][i] = 0;
                break;
            }
        }
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(obstacleGrid[i][j] == 1) ans[i][j] == 0;
                else ans[i][j] = ans[i-1][j] + ans[i][j-1];
            }
        }
        return ans[m-1][n-1];
    }
};
