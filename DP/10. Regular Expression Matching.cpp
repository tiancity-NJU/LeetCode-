/*

    可以参照DFS里面的方法利用回溯的方法解决，也可以利用DP的方法解决
*/

class Solution
{
public:
  
    
    
    
    bool isMatch(string s, string p)
    {
        int slen=s.size(),plen=p.size();
        vector<vector<bool>>DP(slen+1,vector<bool>(plen+1,false));
        DP[0][0]=1;
        
        for(int i=2;i<plen+1;i+=2)
        {
            if(p[i-1]=='*') DP[0][i]=1;
            else break;
        }
        
        for(int i=1;i<slen+1;i++)
        {
            for(int j=1;j<plen+1;j++)
            {
                if(p[j-1]=='*')
                {
                    DP[i][j]=DP[i][j-2] ||(p[j-2]=='.'||p[j-2]==s[i-1])&&DP[i-1][j];
                }
                else
                {
                    DP[i][j]=(p[j-1]=='.'||s[i-1]==p[j-1])&&DP[i-1][j-1];
                }
            }
        }
        
        return DP[slen][plen];
    }
};
