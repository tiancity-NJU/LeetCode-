
/*

  本题虽然是hard，但是本身难度并不大，需要利用DP的方法，假设s1的长度是len1，s2是len2，则设置 len1+1 * len2+1 的数组，其中 DP[i][j] 代表
  s1的前 i 个数 和 s2的前 j 个数能不能和 s3的前 i+j 个匹配上，显然状态转移方程就是
   if(DP[i-1][j]&&s3[i+j-1]==s1[i-1] || DP[i][j-1]&&s3[i+j-1]==s2[j-1])
                    DP[i][j]=1;
                else DP[i][j]=0;
  
  关键就看这个1能不能一直传递下去

*/



class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        
        if(s1=="") return s2==s3;
        if(s2=="") return s1==s3;
        if(s3=="") return false;
        if(s1.size()+s2.size()!=s3.size()) return false; 
        
        vector<vector<bool>>DP(s1.size()+1,vector<bool>(s2.size()+1,false));
        
        
        DP[0][0]=1;
        for(int i=1;i<=s1.size();i++)
            DP[i][0]=(DP[i-1][0]&&s1[i-1]==s3[i-1])?1:0;
        for(int i=1;i<=s2.size();i++)
            DP[0][i]=(DP[0][i-1]&&s2[i-1]==s3[i-1])?1:0;
        
        for(int i=1;i<=s1.size();i++)
            for(int j=1;j<=s2.size();j++)
            {
                if(DP[i-1][j]&&s3[i+j-1]==s1[i-1] || DP[i][j-1]&&s3[i+j-1]==s2[j-1])
                    DP[i][j]=1;
                else DP[i][j]=0;
            }
        
        return DP.back().back();
        
        
    }
};
