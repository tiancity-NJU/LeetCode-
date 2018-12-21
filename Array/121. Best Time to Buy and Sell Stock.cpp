/*
author: ypz
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;
        for(int i = 0; i < prices.size(); i++) {
            if(prices[i] < minPrice) minPrice = prices[i];
            if(prices[i] - minPrice > maxProfit) maxProfit = prices[i] - minPrice;
        }
        return maxProfit;
    }
};


/*
    以上问题可以用DP的方法做，虽然对于该题，没必要浪费O(n) 的空间，但是会是 一种更加通用的思想，只不过DP的每一个值只依赖于前面一个

*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0) return 0;
        
        vector<int>buy(prices.size(),0),sell(prices.size(),0);
        buy[0]=prices[0];
        for(int i=1;i<prices.size();i++)
        {
            buy[i]=min(prices[i],buy[i-1]);
            sell[i]=max(prices[i]-buy[i-1],sell[i-1]);
        }
        
        
        return sell.back();
    }
};
