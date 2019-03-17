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


/*
       易理解的普适性解法
       设定一个k+1 * 2 的dp数组，0表示进行第k次的买，1代表第k次的卖，对于每一天的价格都要遍历一次dp，确保在这一天进行每一次交易的情况
*/


class Solution {
public:
    
 
    
    int deal(vector<int>&prices,int k)
    {
        int ans=0;
        if(2*k>=prices.size())
        {
            for(int i=1;i<prices.size();i++)
            {
                ans+=prices[i]>prices[i-1]?prices[i]-prices[i-1]:0;
            }
            return ans;
        }
        
        vector<vector<int>>DP(k+1,vector<int>(2,INT_MIN));
        DP[0][0]=0;
        DP[0][1]=0;
        
        for(int i=0;i<prices.size();i++)
        {
            for(int j=1;j<k+1;j++)
            {
                DP[j][0]=max(DP[j][0],DP[j-1][1]-prices[i]);
                DP[j][1]=max(DP[j][1],DP[j][0]+prices[i]);
            }
        }
  
        return DP.back()[1];  
    }
   
    int maxProfit(vector<int>& prices) {
        
        return deal(prices,2);
        
        
    }
};
