
/*

  这种子序列匹配的问题，很多都可以转化成DP问题，其中DP[i][j]代表  s的前i个字符和t的前j个字符所代表的状态，但是针对这个问题
  状态转移方程较为抽象，可在纸上画图参考。

*/



class Solution {
public:
    int numDistinct(string s, string t) {
        
        
        vector<vector<int>>DP(s.size()+1,vector<int>(t.size()+1,0));
        
        for(int i=0;i<=s.size();i++)
            DP[i][0]=1;
        
        for(int i=1;i<s.size()+1;i++)
        {
            for(int j=1;j<t.size()+1;j++)
            {
                DP[i][j]+=DP[i-1][j];
                if(s[i-1]==t[j-1]) DP[i][j]+=DP[i-1][j-1];
            }
        }
        
        return DP.back().back();
        
    }
};
