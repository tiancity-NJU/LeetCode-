/*

  对于这种rotated list 的二分查找，一开始的想法就是直接二分，每次都对分出去的另外两边进行同样查找，但是这种方法就是一种复杂版的线性查找，最后还是要
  查找所有的值，那我们可以再其中加入一些判断，如果满足某种条件，则target必不在此区域，那么就能大大缩短时间

*/


class Solution {
public:
    
    
    bool split(vector<int>&nums,int s,int e,int t)
    {
        if(s==e)
        {return nums[s]==t;}
        
        if(nums[s]<nums[e]&&(t<nums[s]||t>nums[e])) return false;
        
        bool left=split(nums,s,(s+e)/2,t);
        bool right=split(nums,(s+e)/2+1,e,t);
        return left | right;
        
    }
    
    
    bool search(vector<int>& nums, int target) {
        if(nums.size()==0) return false;
        return split(nums,0,nums.size()-1,target);
    }
};


/*
    以上方法本质上不算二分的方式，还可以通过另一种二分的方式，只不过需要对rotate分界是否在 left和 right之间进行判断
*/
