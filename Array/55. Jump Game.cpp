/*
    利用最基本的思路，就是循环，然后找每一个位置是否可达,注意边界条件
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        if(nums.size()<2) return true;
        int i;
        for(i=0;i<nums.size();i++)
            if(nums[i]==0) break;
        
        if(i==nums.size()) return true;
        
        if(nums[0]==0) return false;
        vector<bool>DP(nums.size(),false);
        DP[0]=1;
        for(i=0;i<nums.size();i++)
        {
            if(DP[i]==0) continue;
            for(int j=0;j<nums[i];j++)
            {
                DP[i+j+1]=1;
            }
        }
        return DP.back();
    }
};

/*
    还有一种思路就是针对不是最后一个节点的所有0的位置进行考察，观察前面是否能够跳过自己
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        if(nums.size()<2) return true;
        int i;
        for(i=0;i<nums.size();i++)
            if(nums[i]==0) break;
        
        if(i==nums.size()) return true;
        
        if(nums[0]==0) return false;
       
        for(i=0;i<nums.size()-1;i++)
        {
            if(nums[i]==0)
            {
                int k;
                for(k=i-1;k>=0;k--)
                {
                    if(nums[k]>i-k) break;
                }
                if(k==-1) return false;
            }
        }
        return true;
    }
};

/*
        最简单最快的方法，保留一个MAX，记录能够到达的最大下标，同时注意 MAX<i 时，已经无法到达i了，提前结束
*/


class Solution {
public:
    bool canJump(vector<int>& nums) {
        
       
        int MAX=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(MAX<i) break;
            MAX=max(MAX,i+nums[i]);
        }
        return MAX>=nums.size()-1?1:0;
        
    }
};

/*
与第45题同样的思路。
author: ypz
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int last = 0;
        int curr = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(i <= last) curr = max(curr, i + nums[i]);
            else {
                last = curr;
                curr = max(curr, i + nums[i]);
            }
            if(curr >= nums.size() - 1) return true;            // 与下一行不可颠倒，例子:[0]
            if(curr == i) return false;                         // 与上一行不可颠倒，例子:[0]
        }
    }
};
