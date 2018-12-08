

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


/*
  还有一种思路就是调用两次非递归的二分查找，经过测试，耗时基本差不多，相对快一点点
  首先我们需要找左边界，这时采用  int mid=left+(right-left)/2;  使得 mid 更加靠近 left，这样至于每次 nums[mid]<target 的时候才移动left，其他
  时候全部移动right，因为如果nums[mid]==target 可能还不是最左边的，因此需要移动right，让其更加靠近左边界
  另外注意while的条件判断不能出现等于，否则，   right=mid 这一句就无限循环了
*/


class Solution {
public:
    
  
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        ans.push_back(-1);
        ans.push_back(-1);
        if(nums.size()==0) return ans;
        int left=0,right=nums.size()-1;
        while(left<right)
        {
            int mid=left+(right-left)/2;
            if(nums[mid]<target)
                left=mid+1;
            else right=mid;
        }
        if(nums[left]!=target) return ans;
        ans[0]=left;
        left=0,right=nums.size()-1;
        while(left<right)
        {
            int mid=left+(right-left)/2+1;
            if(nums[mid]>target)
                right=mid-1;
            else left=mid;
        }
        
        ans[1]=right;
        return ans;
        
        
    }
};
