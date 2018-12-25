/*
author: ypz
*/

class Solution {
public:
    string convertToTitle(int n) {
        string ans;
        while(n != 0) {
            char temp;
            if(n%26 == 0) {
                temp = 'Z';
                n -= 1;
            }
            else temp = 'A' + n%26 - 1;
            ans = temp + ans;
            n = n / 26;
        }
        return ans;
    }
};
