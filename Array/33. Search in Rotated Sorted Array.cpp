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
