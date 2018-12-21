/*
此题较难，采用动态规划。
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
       可将本思路通用于只准交易K次的情况，以下是交易K次的通用解法，输入prices和最大次数K即可
*/


class Solution {
public:
    
    
    int deal(vector<int>&prices,int k)
    {
        int count=0;
        if(k>=prices.size()/2)    //do inf deal
        {
            for(int i=1;i<prices.size();i++)
                if(prices[i]>prices[i-1]) count+=prices[i]-prices[i-1];
            return count;
        }
        
        vector<int>DP(k*2+2,0);
        for(int i=2;i<DP.size();i+=2)
            DP[i]=INT_MIN;
        
        for(int i=0;i<prices.size();i++)
        {
            for(int j=1;2*j<DP.size();j++)
            {
                DP[2*j]=max(DP[2*j],DP[2*(j-1)+1]-prices[i]);
                DP[2*j+1]=max(DP[2*j+1],DP[2*j]+prices[i]);
            }
        }
        return DP.back();   
    }
    
    
    int maxProfit(vector<int>& prices) {  
        return deal(prices,2);     
    }
};

