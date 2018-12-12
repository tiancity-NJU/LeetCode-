/*
先去除末尾所有空格
author: ypz
*/

class Solution {
public:
    int lengthOfLastWord(string s) {
        while(s[s.size() - 1] == ' ') {
            if(s.size() == 0) break;
            s.erase(s.end() - 1);
        }
        if(s.size() == 0) return 0;
        int ans = 0;
        for(int i = s.size() - 1; i >= 0; i--) {
            if(s[i] != ' ') ans++;
            else break;
        }
        return ans;
    }
};
