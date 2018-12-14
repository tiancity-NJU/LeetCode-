

/*
  一开始看到这个问题，最简单的想法还是DFS的方式，并且在其中加入一些约束，跳出一些现有长度已经大于最短长度的位置，虽然这样能够缩短时间，但是还是会超时
  一般dfs解决不了的问题就需要考虑DP的方法了
  
*/

class Solution {
public:
    
    void dfs(int remain,int len,int&ans)
    {
        if(ans!=0&&len>ans) return;
        if(remain==0)
        {
            if(ans==0) ans=len;
            else ans=min(ans,len);
            return;
        }
        int64_t k=0;
        while(k*k<=remain) k++;
        
        for(int i=k;i>0;i--)
        {
            dfs(remain-i*i,len+1,ans);
        }
    }
    
    
    int numSquares(int n) {
        int ans=INT_MAX;
        dfs(n,0,ans);
        return ans;
    }
};

/*

   使用DP，可以发现 DP[i]=min(DP[i-1],DP[i-4],DP[i-9].....)+1
   发现了规律就好办了

*/
class Solution {
public:
    int numSquares(int n) {
        vector<int>DP(n+1,0);
        for(int i=1;i<n+1;i++)
        {
            DP[i]=DP[i-1]+1;
            for(int k=1;i-k*k>=0;k++)
            {
                DP[i]=min(DP[i],DP[i-k*k]+1);
            }
        }
        return DP.back();
    }
};
