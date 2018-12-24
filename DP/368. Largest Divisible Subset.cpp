
/*
  一开始看到这种找具体情况的问题，就想着回溯，果然溢出了，在此记录一下，如果没有过大的限制，这也是一种通用可行的方法
  但是就算是对应这个方法，还是存在可以优化的点，比如 1 3 9 18 ....这样的序列，在 for里面如果3开头，那9开头的就可以不用跑了，利用一个O(n) 的mask
  可以实现这种方式
*/


class Solution {
public:
    
    void dfs(vector<int>&nums,vector<int>&tmp,vector<int>&ans,int base)
    {
        if(tmp.size()>ans.size())
        {
            ans.assign(tmp.begin(),tmp.end());
        }
        
        for(int i=base+1;i<nums.size();i++)
        {
            if(nums[i]%tmp.back()==0)
            {
                tmp.push_back(nums[i]);
                dfs(nums,tmp,ans,i);
                tmp.pop_back();
            }
        }
    }
    
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        vector<int>ans;
        vector<int>tmp;
        
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size();i++)
        {
            tmp.push_back(nums[i]);
            dfs(nums,tmp,ans,i);
            tmp.pop_back();
        }
        
        return ans;
    }
};


/*
  看到该问题涉及的相关问题竟然是DP，之前认为DP只能数情况数目的想法可以需要转变一下，利用DP后，可以打败95%的方法
*/

class Solution {
public:
    
  
    
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        vector<int>ans;
     
        if(nums.size()==0) return ans;
        sort(nums.begin(),nums.end());
        
        vector<int>DP(nums.size(),1);
        
        
        for(int i=0;i<nums.size();i++)
        {
           for(int j=0;j<i;j++)
           {
               if(nums[i]%nums[j]==0)
               {
                   DP[i]=max(DP[i],DP[j]+1);
               }
           }
        }
        
        int pos=0;
        int MAX=1;
        for(int i=0;i<nums.size();i++)
        {
            if(DP[i]>MAX)
            {
                MAX=DP[i];
                pos=i;
            }
        }
        ans.insert(ans.begin(),nums[pos]);
        MAX--;
        for(int i=pos-1;i>=0;i--)
        {
            if(nums[pos]%nums[i]==0&&DP[i]==MAX)
            {
                ans.insert(ans.begin(),nums[i]);
                pos=i;
                MAX--;
            }
        }
        return ans;
    }
};


