
/*
  线性方法或者二分法，二分法注意处理边界，以及在0, size开外的部分
  寻找数值问题   (left<=right)   left=mid+1    right=mid-1;

*/



class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int left=0,right=nums.size()-1;
        if(nums[left]>=target) return left;
        if(nums[right]<target) return right+1;
        if(nums[right]==target) return right;
        
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            if(nums[mid]==target) return mid;
            if(nums[mid]<target)
            {
                left=mid+1;
            }
            else right=mid-1;
        }
        return max(left,right);
        
    }
};
