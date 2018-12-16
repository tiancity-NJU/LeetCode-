
/*
  一开始想着这一题没什么难度，主要就是统计有多少种组合即可，按照之前的coin change的框架直接写，最后发现得到的答案往往多余标准答案，才发现
  其中包含了很多重复的答案，比如对于[1,2,5] amount=3 按照我们的方法就会得到1,1,1    1,2  2,1 三个答案，现在就压想办法避免这种重复，想了很久
  才发现非常的简单，我们只需要保证coin是升序选取就行了，可以将两个for循环的位置调换一下，每个DP[i] 都是慢慢累加起来的

*/


class Solution {
public:
    int change(int amount, vector<int>& coins) {
        
        vector<int>DP(amount+1,0);
        sort(coins.begin(),coins.end());
        
        DP[0]=1;
        for(int i=0;i<coins.size();i++)
        {
             for(int j=coins[i];j<=amount;j++)
            { 
                DP[j]+=DP[j-coins[i]];
            }
        }
        return DP[amount];
    }
};
