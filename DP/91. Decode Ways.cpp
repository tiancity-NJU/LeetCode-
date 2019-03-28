class Solution {
public:
    int numDecodings(string s) {
        if(s[0] == '0') return 0;
        if(s.size() == 1) return 1;
        vector<int> dp(s.size());
        dp[0] = 1;
        if(s[1] == '0' && s[0] >= '3') return 0;
        if((s[0] < '2' && s[1] != '0') || (s[0] == '2' && s[1] <= '6' && s[1] != '0')) dp[1] = 2;
        else dp[1] = 1;
        for(int i = 2; i < s.size(); i++) {
            if(s[i] == '0') {
                if(s[i-1] == '0' || s[i-1] >= '3') return 0;
                dp[i] = dp[i-2];
            }
            else if(s[i] <= '6') {
                if(s[i-1] == '0') dp[i] = dp[i-1];
                else if(s[i-1] <= '2') dp[i] = dp[i-1] + dp[i-2];
                else dp[i] = dp[i-1];
            }
            else {
                if(s[i-1] == '0') dp[i] = dp[i-1];
                else if(s[i-1] <= '1') dp[i] = dp[i-1] + dp[i-2];
                else dp[i] = dp[i-1];
            }    
        }
        return dp[s.size()-1];
    }
};
