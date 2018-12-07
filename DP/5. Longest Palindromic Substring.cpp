





class Solution {
public:
    string longestPalindrome(string s) {
        
        
        vector<vector<int>>DP(s.size(),vector<int>(s.size(),0));
        
        
        for(int i=0;i<s.size();i++)
        {
            DP[i][i]=1;
            if(i+1<s.size()&&s[i]==s[i+1]) DP[i][i+1]=1;
        }
        
        for(int step=3;step<=s.size();step++)
        {
            for(int i=0;i<s.size();i++)
            {
                int j=i+step-1;
                if(j<s.size()&&s[i]==s[j]&&DP[i+1][j-1]) DP[i][j]=1;
            }
        }
    
        int MAX=0;
        int left=0,right=0;
        for(int i=0;i<s.size();i++)
            for(int j=i;j<s.size();j++)
            {
                if(DP[i][j]==1&&j-i+1>MAX)
                {
                    MAX=j-i+1;
                    left=i;
                    right=j;
                }
            }
        
        return s.substr(left,right-left+1);
        
    }
};
