// author: ypz
// 数组dp表示落地到第i位的最低代价，注意返回值取落地到第n位和第n-1位中代价的较小者。

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if(cost.size() == 0) return 0;
        if(cost.size() == 1) return cost[0];
        vector<int> dp(cost.size(), 0);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i = 2; i < cost.size(); i++) 
            dp[i] = min(dp[i-1], dp[i-2]) + cost[i];
        return min(dp[cost.size()-1], dp[cost.size()-2]);
    }
};
