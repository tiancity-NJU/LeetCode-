/*
此题较难，采用动态规划
buy1: 当前日期下最大化第一次买时的收益
sell1:当前日期下最大化第一次卖时的收益
buy2: 当前日期下最大化第二次买时的收益
sell2:当前日期下最大化第二次卖时的收益
author: ypz
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy1 = INT_MIN;
        int buy2 = INT_MIN;
        int sell1 = 0;
        int sell2 = 0;
        for(int i = 0; i < prices.size(); i++) {
            buy1 = max(buy1, 0 - prices[i]);
            sell1 = max(sell1, buy1 + prices[i]);
            buy2 = max(buy2, sell1 - prices[i]);
            sell2 = max(sell2, buy2 + prices[i]);
        }     
        return sell2;
    }
};
