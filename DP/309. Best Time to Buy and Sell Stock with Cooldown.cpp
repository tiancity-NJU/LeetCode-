
/*

    该题虽然能够很容易的想到利用DP，但是由于冷却时间的加入，导致状态转移方程较难确定，我们需要维护一个  len+1 * 2的DP数组  0代表当天买进  1代表当天
    卖出，那么当前买进需要基于前天卖出（1天的冷却）和之前的0状态的较大者，同理 1也是一样，但是不用考虑冷却时间
    方便起见DP从1开始。  

*/



class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>DP(prices.size()+1,vector<int>(2,0));
        if(prices.size()<2) return 0;
        
        //   0 is buy     1 is sell
        DP[1][0]=-prices[0];
        

        for(int i=2;i<prices.size()+1;i++)
        {
            DP[i][0]=max(DP[i-2][1]-prices[i-1],DP[i-1][0]);
            DP[i][1]=max(DP[i-1][0]+prices[i-1],DP[i-1][1]);
        }
        
        return DP.back()[1];
        
        
    }
};
