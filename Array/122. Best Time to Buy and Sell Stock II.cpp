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

/*
    可以当天卖然后当天买，以为不能在同一天卖买，i+=1 和 i+=2的区别
    也可以直接扫描，只要前后两天是增序，就加上差值
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        if(prices.size()==0) return 0;
        int i=1;
        
        int count=0;
        while(i<prices.size())
        {
            while(i<prices.size()&&prices[i]<prices[i-1]) i++;
            if(i>=prices.size()) break;
            
            count+=prices[i]-prices[i-1];
            i+=1;
        }
        
        return count;
        
    }
};
