/*
author:ypz
暴力搜索超时，采用动态规划。
在数组dp[j]中，两个true中间的子串表示是匹配成功的。
*/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if(wordDict.size() == 0) return false;
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for(int i = 1; i <= s.size(); i++) {
            for(int j = i - 1; j >= 0; j--) {
                if(dp[j]) {
                    string sub_s;
                    sub_s = s.substr(j, i - j);
                    if(find(wordDict.begin(), wordDict.end(), sub_s) != wordDict.end()) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[s.size()];
    }
};
