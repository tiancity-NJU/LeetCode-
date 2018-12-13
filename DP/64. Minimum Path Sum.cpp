/*
  很基础的一道DP问题，为了保证循环时候的统一性（主要是边界性，在最外面套上一层）
  author: ztc
*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        if(grid.size()==0) return 0;
        vector<vector<int>>DP(grid.size()+1,vector<int>(grid[0].size()+1,0));
        for(int i=0;i<DP.size();i++)
        {
            DP[i][0]=INT_MAX;
        }
        for(int i=0;i<DP[0].size();i++)
        {
            DP[0][i]=INT_MAX;
        }
        DP[1][1]=grid[0][0];
        
        for(int i=1;i<=grid.size();i++)
        {
            for(int j=1;j<=grid[0].size();j++)
            {
                if(i==1&&j==1) continue;
                DP[i][j]=min(DP[i-1][j],DP[i][j-1])+grid[i-1][j-1];
            }
        }
        return DP.back().back();
    }
};

/*
  本来以为这样就结束了，后来突然想到，DP的为一个位置只和前面和上面一个有关，用一维数组是不是就能办到，这样能够保证
  运行时间O(n2)  空间代价O(n)
  author: ztc
*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        if(grid.size()==0) return 0;
        vector<int>DP(grid[0].size()+1,0);
        DP[0]=INT_MAX;
        DP[1]=grid[0][0];
        for(int i=2;i<DP.size();i++)
            DP[i]=DP[i-1]+grid[0][i-1];
        
        for(int i=1;i<grid.size();i++)
        {
            for(int j=1;j<=grid[0].size();j++)
            {
                DP[j]=min(DP[j-1],DP[j])+grid[i][j-1];
            }
        }
        return DP.back();
    }
};


/*
动态规划，ans[i][j] = min(grid[i][j] + ans[i-1][j], grid[i][j] + ans[i][j-1]);
author: ypz
*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> ans(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++) {
            if(i == 0) ans[i][0] = grid[i][0];
            else ans[i][0] = grid[i][0] + ans[i-1][0];
        }
        for(int j = 1; j < n; j++) ans[0][j] = grid[0][j] + ans[0][j-1];
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) ans[i][j] = min(grid[i][j] + ans[i-1][j], grid[i][j] + ans[i][j-1]);
        }
        return ans[m-1][n-1];
    }
};
