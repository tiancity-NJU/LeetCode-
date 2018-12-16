
/*
    主要是使用DP的方式解决，还有一种回溯的策略，容易在边界处理时出错，只有一位数时长度可以10，其余的首位都不可以是0
 
*/
class Solution {
public:
    
    int serarch(int remain,vector<bool>&used)
    {
        if(remain==0) return 1;
        int count=0;
        for(int i=0;i<10;i++)
        {
            if(used[i]) continue;
            used[i]=1;
            count+=serarch(remain-1,used);
            used[i]=0;
        }
        return count;
    }
    
    
    int countNumbersWithUniqueDigits(int n) {
        
        if(n>10)
            return countNumbersWithUniqueDigits(10);
        
        if(n==1) return 10;
        if(n==0) return 1;
        
        
        int count=10;
        vector<bool>used(10,0);
        for(int k=2;k<=n;k++)
        for(int i=1;i<10;i++)
        {
            used[i]=1;
            count+=serarch(k-1,used);
            used[i]=0;
        }
        return count;
           
    }
};
