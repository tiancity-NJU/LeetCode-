
/*
  经典的DP问题，难点主要在初始化以及状态转移方程需要分情况的这两点：
   1.初始化，需要将coins在DP对应位置初始化为1，否则更新不起来
   2.DP初始化是0，所以在碰到min的时候会出错，所以需要在不是0的前提下才进行min的比较，另外如果 i-coins[j]没有对应答案，即直接跳过

*/




class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        
        if(amount==0) return 0;
        vector<int>DP(amount+1,0);
        for(auto c:coins)
        {
            if(c<=amount) DP[c]=1;
        }
        
        for(int i=1;i<=amount;i++)
        {
            for(int j=0;j<coins.size();j++)
            {
                if(i-coins[j]<0 || DP[i-coins[j]]==0) continue;
                if(DP[i]==0)
                    DP[i]=DP[i-coins[j]]+1;
                else DP[i]=min(DP[i],DP[i-coins[j]]+1);
            }
        }
        return DP[amount]==0?-1:DP[amount];
    }
};
