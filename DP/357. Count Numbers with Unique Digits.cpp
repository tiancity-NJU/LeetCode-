
/*
  看上去似乎比较复杂，找不到思路，一开始想的策略是统计包含重复数字的个数，然后发现这样根本没法计算，突然想到，对于一个n位数，各个数字
  不重复，不就是0-9的10个数字的排列。因此利用一个函数计算对应位数的排列数，累加起来即可，进一步可以把DP数组换成一个数字即可
*/



class Solution {
public:
    
    int con(int n)
    {
        if(n>10) return 0;
        if(n==1) return 10;
        int num=9;
        for(int i=9;i>10-n;i--)
            num*=i;
        return num;
    }
    
    
    int countNumbersWithUniqueDigits(int n) {
        
        vector<int>DP(n+1,0);
        if(n==0) return 1;
        for(int i=1;i<=n;i++)
        {
            int num=con(i);
            DP[i]=DP[i-1]+num;
        }
        return DP[n];
        
        
        
    }
};

/*
    还有一种回溯的策略，容易在边界处理时出错，只有一位数时长度可以10，其余的首位都不可以是0
 
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
