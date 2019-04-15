/*
    author: ztc
    最容易想到的方法就是DP，关键在于DP数组的设置以及状态转移方程
    先是考虑一维，但是数值含义不好定义，后来一想，这种问题是一种很典型的考虑状态能不能传递的问题，所以采用二维数组，DP[i][j]代表s[i]->s[j]是否
    是回文，然后向两边传递的问题，一开始  DP[i][i]=1   s[i]==s[i+1] -> DP[i][i+1]=1  这是对于奇回文 偶回文的初始化，接着只需要对步长迭代，将
    DP向两边扩展即可。
    和 97 题很像， 状态1的传递
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
  author: ypz
  动态规划，初始化为mtx[i][i] = true，mtx[i][i+1] = true，
  若mtx[i+1][j-1] = true且s[i] == s[j]则mtx[i][j] = true。
*/

class Solution {
public:
    string longestPalindrome(string s) {
        string ans;
        if(s.size() <= 1) return s;
        vector<vector<bool>> mtx(s.size(), vector<bool>(s.size(), false));
        for(int i = 0; i < s.size(); i++) {
            mtx[i][i] = true;
            if(i+1 < s.size() && s[i+1] == s[i]) 
                mtx[i][i+1] = true;
        }
        for(int i = s.size() - 1; i >= 0; i--) {
            for(int j = i + 1; j < s.size(); j++) {
                if(j-1 >= i+1 && s[i] == s[j] && mtx[i+1][j-1] == true) 
                    mtx[i][j] = true;
            }
        }
        int begin = 0;
        int gap = -1;
        for(int i = 0; i < s.size(); i++) {
            for(int j = i; j < s.size(); j++) {
                if(mtx[i][j] == true && j-i+1 > gap) {
                    begin = i;
                    gap = j - i + 1;
                }
            }
        }
        ans = s.substr(begin, gap);
        return ans;
    }
};
