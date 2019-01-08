class Solution {
public:
    
    /*
    author: ypz
    借鉴approach3
    */
    
    int longestValidParentheses(string s) {
        if(s.size() < 2) return 0;
        stack<int> list;
        list.push(-1);          // 初始化-1入栈
        int ans = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(')  list.push(i);
            else if(s[i] == ')') {
                list.pop();    // 此时栈顶为括号抵消后的上一个索引
                if(list.size() == 0) list.push(i);     // 若栈为空，将当前ans清零重新开始计算有效长度，将当前索引入栈
                else ans = max(ans, i - list.top());   
            }
        }
        return ans;
    }
};


/*
        DP的方法
        DP的每一个值表示以该符号为终结符号的左右括号长度总长度，解决的是 ((()))这种情况，然后dp[i]+=dp[i-dp[i]]表示加上在这个嵌套之前的总长度
        比如 (())((())) 对于最后一个)  DP先是4+2=6，再加上 前面的 i-dp[i] 的4
*/


class Solution {
public:
    int longestValidParentheses(string s) {
        int result=0;
        s=')'+s;
        vector<int> dp(s.length(),0);
        for(int i=1;i<s.length();i++)
        {
            if(s[i]==')')
            {
                if(s[i-1-dp[i-1]]=='(') dp[i]=dp[i-1]+2;
                dp[i]+=dp[i-dp[i]];
            }
            result=max(result,dp[i]);
        }
        return result;
    }
};
