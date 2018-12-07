class Solution {
public:
    
    /*
    author:ypz
    */
    
    vector<int> searchRange(vector<int>& nums, int target) {
        // 首先计算最左的索引值
        int left = 0, right = nums.size();
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] >= target) right = mid;
            else left = mid + 1;
        }
        if(left == nums.size() || nums[left] != target) return {-1, -1};
        // 其次计算最右的索引值
        int start = left;
        right = nums.size();
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] > target) right = mid;
            else left = mid + 1;
        }
        int end = left - 1; 
        return {start, end};
    }
};
