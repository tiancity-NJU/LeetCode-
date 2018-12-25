/*
author: ypz
*/

class Solution {
public:
    int titleToNumber(string s) {
        int ans = 0;
        while(s.size() != 0) {
            ans += s[0] - 'A' + 1;
            s.erase(s.begin());
            if(s.size() != 0) ans = ans * 26;
        }
        return ans;
    }
};
