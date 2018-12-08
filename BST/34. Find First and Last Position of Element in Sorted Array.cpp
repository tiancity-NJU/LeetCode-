

/*

  一般来说，如果需要对二分以后的两边都需要进行查找的话，建议使用 函数递归
  如果仅仅只是查找一个目标，只在二分的一边查找，那么就通过  left 和 right 进行，防止进行函数调用所浪费的空间

*/


class Solution {
public:
    
    void split(vector<int>&nums,int start,int end,int target,vector<int>&ans)
    {
        
        if(start==end)
        {
            if(nums[start]==target) 
            {
                if(ans[0]<0) ans[0]=start;
                else ans[0]=min(ans[0],start);
                ans[1]=max(ans[1],start);
            }
            return;
        }
        if(nums[start]>target || nums[end]<target) return;
        split(nums,start,start+(end-start)/2,target,ans);
        split(nums,1+start+(end-start)/2,end,target,ans);
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        ans.push_back(-1);
        ans.push_back(-1);
        if(nums.size()==0) return ans;
        split(nums,0,nums.size()-1,target,ans);
        return ans;
    }
};
