/*
先补齐，然后像竖式一样加法。
j用来存储当前位的结果和进位。
author: ypz
*/

class Solution {
public:
    string addBinary(string a, string b) {
        int n = max(a.size(), b.size());
        while(a.size() < n) a = "0" + a;
        while(b.size() < n) b = "0" + b;
        string ans = "";
        int j = 0; 
        for(int i = n - 1; i >= 0; i--) {
            j += (a[i] - '0') + (b[i] - '0');
            ans = (char)(j % 2 + '0') + ans;
            j = j / 2;
        }
        if(j == 1) ans = "1" + ans;
        return ans;
    }
};
