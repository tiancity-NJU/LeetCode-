/*
author: ypz
*/

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.size() == 0)
            return false;
        if(nums.size() == 1)
            return nums[0] == target;
        int left = 0, right = nums.size() - 1;
        while(left <= right) {
            
            // 跳过重复的部分
            while(left < right && nums[left] == nums[left + 1]) 
                left++;
            while(left < right && nums[right] == nums[right - 1]) 
                right--;
            if(left == right) 
                return nums[left] == target;
            
            int mid = (left + right) / 2;
            if(nums[mid] == target) 
                return true;
            
            // 左半段为升序
            if(nums[left] <= nums[mid]) {
                if(nums[left] <= target && nums[mid] > target)  
                    right = mid - 1;
                else 
                    left = mid + 1;
            }
            
            // 右半段为升序
            else {
                if(nums[mid + 1] <= target && nums[right] >= target) 
                    left = mid + 1;
                else 
                    right = mid - 1;
            }
        }
        return false;
    }
};
