/*
author: ztc
这一题还是放在BST里更加合适，相对于前一题需要返回树的结构，这一题只需要统计即可，第一直觉就是将上一题的结果中新建树换成加法即可
*/

class Solution {
public:
    
    int find(int s,int n)
    {
        if(n==0) return 1;
        if(n==1) return 1;
        
        int count=0;
        for(int i=0;i<n;i++)
        {
            int left=find(s,i);
            int right=find(s,n-i-1);
            count+=left*right;
        }
        return count;
    }
    
    int numTrees(int n) {
        return find(1,n);
    }
};

/*
  author: ztc
  不出所料，严重超时，在n=18的时候，就已经需要600ms了，仔细想了想，  大小为n的树的数量不就是  子树一次为 0 n-1; 1 n-2;...情况相乘的和
  利用DP即可
*/

class Solution {
public:
    
    int numTrees(int n) {
        
        vector<int>DP(n+1,0);
        DP[0]=1;
        for(int i=1;i<=n;i++)
        {
            for(int k=0;k<i;k++)
            {
                DP[i]+=DP[k]*DP[i-k-1];
            }
        }
        
        return DP.back();
    }
};

/*
author: ypz
二叉查找树可以任意取根，满足中序遍历有序即可。
取一个结点为根，切成左右子树，以该结点为根的可行二叉树数量为左右子树可行二叉树数量的乘积。
因此总数量是将以所有结点为根的可行结果累加起来。
*/

class Solution {
public:
    int calculate(int begin, int end) {
        if(begin >= end) return 1;
        int ans = 0;
        for(int i = begin; i <= end; i++) ans += calculate(begin, i - 1) * calculate(i + 1, end);
        return ans;
    }
    
    int numTrees(int n) {
        int result = calculate(1, n);
        return result;
    }
};
