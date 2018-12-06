/*
  本来一看到有序数组就想到O(n)的话肯定会超时，所以用BST，但是这个似乎关系不大，用线性时间即可
  
  一个string s存储中间结果，一个baseIndex记录这个连续序列的初始位置，用来区分   0   0->2  这两种形式，另外要单独考虑到结尾的情况，因此在for循环上
  加入一次循环，在内部简单区分即可，省的在写后处理，总体比较简单


*/



class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        
        vector<string>ans;
        if(nums.size()==0) return ans;
        
        int baseIndex=0;
        string s=to_string(nums[0]);
        for(int i=1;i<=nums.size();i++)
        {
            if(i<nums.size()&&nums[i]==nums[i-1]+1) continue;
            if(i==baseIndex+1)
            {
                ans.push_back(s);
                if(i<nums.size()) s=to_string(nums[i]);
                baseIndex=i;
            }
            else
            {
                s+="->"+to_string(nums[i-1]);
                ans.push_back(s);
                if(i<nums.size()) s=to_string(nums[i]);
                baseIndex=i;
            }
        }
        
        return ans;
    }
};
