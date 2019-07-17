// author: ypz

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> con;
        for(auto s:tokens) {
            if(s != "+" && s != "-" && s != "*" && s != "/")
                con.push(stoi(s));
            else { 
                int x2 = con.top();
                con.pop();
                int x1 = con.top(); // 注意x1,x2不可颠倒，否则会出现除数为0
                con.pop();
                int x = 0;
                switch(s[0]) {      // 注意swich里面必须是整型，若为s会报错
                    case '+': x = x1 + x2; break;
                    case '-': x = x1 - x2; break;
                    case '*': x = x1 * x2; break;
                    case '/': x = x1 / x2; break;
                }
                con.push(x);
            }
        }
        return con.top();
    }
};
