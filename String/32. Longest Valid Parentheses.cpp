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
