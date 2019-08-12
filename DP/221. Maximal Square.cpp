/*
   author: ztc
   相比于之前的最大矩阵，本题相对约束多一点，状态方程比较好确定，并且不需要特别的初始化，直接利用 m+1 * n+1 的数组即可
*/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        
        if(matrix.size()==0) return 0;
        int m=matrix.size(),n=matrix[0].size();
        
        vector<vector<int>>DP(m+1,vector<int>(n+1,0));
        
        int ans=0;
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(matrix[i-1][j-1]=='1')
                {
                    DP[i][j]=min(DP[i-1][j-1],min(DP[i-1][j],DP[i][j-1]))+1;
                    ans=max(ans,DP[i][j]);
                }
            }
        }
         
        return ans*ans;
    }
};

/*
  author: ztc
  常见的一种优化方法能将空间复杂度降低到O(n)，由于DP[i][j]需要用到DP[i-1][j-1]和 DP[i][j-1] 无论是左边循环还是右边循环都不能通过一行搞定
  所以利用滚轮数组
*/
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        
        if(matrix.size()==0) return 0;
        int m=matrix.size(),n=matrix[0].size();
        
        vector<vector<int>>DP(2,vector<int>(n+1,0));
        
        int ans=0;
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(matrix[i-1][j-1]=='1')
                {
                    DP[i%2][j]=min(DP[(i-1)%2][j-1],min(DP[(i-1)%2][j],DP[i%2][j-1]))+1;
                    ans=max(ans,DP[i%2][j]);
                }
            }
        }
         
        return ans*ans;
    }
};


/*
author: ypz
动态规划，可以用二维数组储存以该索引为右下角的最大边长。
最优解为用一维数组存储，dp[i]对应(i,j)，dp[i-1]对应(i,j-1)，prev对应(i-1,j-1)。
*/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int ans = 0;
        if(matrix.size() == 0)
            return ans;
        if(matrix[0].size() == 0)
            return ans;
        vector<int> dp(matrix[0].size(), 0);
        for(int i = 0; i < matrix.size(); i++) {
            int temp, prev;
            for(int j = 0; j < matrix[0].size(); j++){
                temp = dp[j];
                if(i == 0 || j == 0 || matrix[i][j] == '0')
                    dp[j] = matrix[i][j] - '0';
                else {
                    dp[j] = min(min(temp, dp[j-1]), prev) + 1;
                }
                ans = max(ans, dp[j]);
                prev = temp;
            }
        }
        return ans * ans;
    }
};
