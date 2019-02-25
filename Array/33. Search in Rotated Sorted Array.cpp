class Solution {
public:

    /*
    author: ypz
    */
    int search(vector<int>& nums, int target) {
        
        if(nums.size() == 0) return -1;
        int left = 0;
        int right = nums.size() - 1;
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] == target) return mid;
            
            // 左半段为升序
            if(nums[left] < nums[mid]) {
                if(nums[left] <= target && nums[mid] > target)  right = mid - 1;
                else left = mid + 1;
            }
            
            // 右半段为升序
            else {
                if(nums[mid + 1] <= target && nums[right] >= target) left = mid + 1;
                else right = mid - 1;
            }
        }
        if(nums[left] == target) return left;
        else return -1;
    }
};

/*
  思想不难理解，利用二分，mid左右必然有一个是有序的，对有序情况进行判断，不满足直接进入另一部分
*/


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size(), left = 0, right = len-1;
        while(left <= right)
        {
            int mid = (left+right)/2;
            if(nums[mid] == target) return mid;
            if(nums[mid] >= nums[0])
            {
                if(target < nums[mid] && target >= nums[0]) right = mid-1;
                else left = mid+1;
            }
            else
            {
                if(target > nums[mid] && target < nums[0]) left = mid+1;
                else right = mid-1;
            }
        }
        return -1;
    }
};
