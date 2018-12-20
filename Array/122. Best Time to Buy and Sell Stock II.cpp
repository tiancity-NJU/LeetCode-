/*
author: ypz
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        for(int i = 0; i < prices.size(); i++) {
            if(i != 0) {
                if(prices[i] > prices[i-1]) ans += prices[i] - prices[i-1];
            }
        }
        return ans;
    }
};
