/*
author: ypz
*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        while(k != 0) {
            int temp = nums[nums.size() - 1];
            nums.erase(nums.begin() + nums.size() - 1);
            nums.insert(nums.begin(), temp);
            k--;
        }
    }
};
