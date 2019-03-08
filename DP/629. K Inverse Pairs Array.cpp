
/*

  有点难的DP，具体参考https://www.cnblogs.com/grandyang/p/7111385.html
  状态转移很难确定，核心思想是  n+1时多加的一个数能够和前面n个数构成  0,1,2,3,4...n个逆序对，当n>k时就不用了

*/

class Solution {
public:
    int kInversePairs(int n, int k) {
        int M = 1000000007;
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        dp[0][0] = 1;
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                for (int m = 0; m <= k; ++m) {
                    if (m - j >= 0 && m - j <= k) {
                        dp[i][m] = (dp[i][m] + dp[i - 1][m - j]) % M;
                    }
                }
            }
        }
        return dp[n][k];
    }
};



class Solution {
public:
    int kInversePairs(int n, int k) {
        int M = 1000000007;
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            dp[i][0] = 1;
            for (int j = 1; j <= k; ++j) {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % M;
                if (j >= i) {
                    dp[i][j] = (dp[i][j] - dp[i - 1][j - i] + M) % M;
                }
            }
        }
        return dp[n][k];
    }
};
