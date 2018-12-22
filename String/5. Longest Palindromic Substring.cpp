


/*
  
    最容易想到的方法就是DP，关键在于DP数组的设置以及状态转移方程
    先是考虑一维，但是数值含义不好定义，后来一想，这种问题是一种很典型的考虑状态能不能传递的问题，所以采用二维数组，DP[i][j]代表s[i]->s[j]是否
    是回文，然后向两边传递的问题，一开始  DP[i][i]=1   s[i]==s[i+1] -> DP[i][i+1]=1  这是对于奇回文 偶回文的初始化，接着只需要对步长迭代，将
    DP向两边扩展即可。


*/


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


/*
  或者直接在里面保存max，但是这样容易出错，可以作为上述方法的代码优化，时间复杂度还是一致的，但是对于大规模数据，运行时间缩小了一倍
*/

class Solution {
public:
    string longestPalindrome(string s) {
        
        if(s.size()==0) return s;
        vector<vector<bool>>DP(s.size(),vector<bool>(s.size(),false));
        int mi=0,mj=1;
        int maxLen=1;
        for(int i=0;i<s.size();i++)   
        {
            DP[i][i]=1;
            if(i!=0&&s[i-1]==s[i]) 
            {
                DP[i-1][i]=1;
                if(maxLen<2){maxLen=2;mi=i-1;mj=i;}
            }
        }
        for(int len=3;len<=s.size();len++)
        {
            for(int i=0;i+len-1<s.size();i++)
            {
                int j=i+len-1;
                if(s[i]==s[j]&&DP[i+1][j-1]) 
                {
                    DP[i][j]=1;
                    if(len>maxLen)
                    {
                        maxLen=len;
                        mi=i;mj=j;
                    }
                }
            }
        }
       return s.substr(mi,maxLen);
     
    }
};


/*
    还有一个经典算法 Manacher 专门用来解决最长回文问题，时间复杂度 O(n)

*/

