


/*
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
