/*
Two pointers.
将0都移到左边，2都移到右边，1留着不动。
author: ypz
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        for(int i = 0; i <= right; ) {
            if(nums[i] == 0) {
                nums[i] = nums[left];
                nums[left] = 0;
                left++;
                i++;
            }
            else if(nums[i] == 1) i++;
            else {
                nums[i] = nums[right];
                nums[right] = 2;
                right--;
            }
        }
    }
};
