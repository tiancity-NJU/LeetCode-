
/*
    利用三维DP， DP[mi][ni][Ni] 代表从 mi ni位置最多走Ni步有多少种情况
    一开始尝试把  边界的Ni 从 1-N全部置 1 或 2，即先初始化边界，然后对N步进行  m*n 次的循环，但是个别例子会报错
    以下是他人方法的修改

*/


class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        
        if(m==0 || n==0 || N==0) return 0;
        int M=1000000007;
        vector<vector<vector<int64_t>>>dp(m,vector<vector<int64_t>>(n,vector<int64_t>(N+1,0)));
        
        int direction[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
        
        
            for(int Ni=1;Ni<=N;Ni++)
            {
                for(int mi=0;mi<m;mi++)
                {
                    for(int ni=0;ni<n;ni++)
                    {
                        dp[mi][ni][Ni] = ((mi == 0 ? 1 : dp[mi - 1][ni][Ni - 1]) + (mi == m - 1? 1 : dp[mi + 1][ni][Ni-1])
            + (ni == 0 ? 1 : dp[mi][ni - 1][Ni - 1]) + (ni == n - 1 ? 1 : dp[mi][ni + 1][Ni - 1])) % 1000000007;
                    }
                }
            }
        
        return dp[i][j][N];
  
    }
};

/*
    以下是个别无法通过的解法
*/

class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        
        if(m==0 || n==0 || N==0) return 0;
        int M=1000000007;
        vector<vector<vector<int64_t>>>dp(m,vector<vector<int64_t>>(n,vector<int64_t>(N+1,0)));
        
        int direction[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
        
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                for(int k=1;k<=N;k++)
                {
                if(i==0 || i==m-1) dp[i][j][k]+=1;
                if(j==0 || j==n-1) dp[i][j][k]+=1;
                }
            }
            for(int k=1;k<=N;k++)
            {
                for(int i=0;i<m;i++)
                {
                    for(int j=0;j<n;j++)
                    {
                        for(int d=0;d<4;d++)
                        {
                            if(i-direction[d][0]>=0&&i-direction[d][0]<m && j-direction[d][1]>=0&&j-direction[d][1]<n)
                                dp[i][j][k]+=dp[i-direction[d][0]][j-direction[d][1]][k-1]%M;
                        }
                        
                    }
                }
            }
        return dp[i][j][N];
    }
};
