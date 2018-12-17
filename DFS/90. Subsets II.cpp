/*
思路同第78题，注意将nums排序后，每次回溯避免起始元素相同即可。
author: ypz
*/

class Solution {
public:
    void backTracking(vector<vector<int>> &ans, vector<int> &curr, vector<int> &nums, int k) {
        if(curr.size() == k) ans.push_back(curr);
        else {
            if(nums.size() == 0) return;
            for(int i = 0; i < nums.size(); i++) {
                if(i != 0 && nums[i] == nums[i - 1]) continue;
                vector<int> curr_temp(curr);
                vector<int> nums_temp(nums);
                curr_temp.push_back(nums[i]);
                nums_temp.erase(nums_temp.begin(), nums_temp.begin() + i + 1);
                backTracking(ans, curr_temp, nums_temp, k);
            }
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        sort(nums.begin(), nums.end());
        for(int i = 0; i <= nums.size(); i++) backTracking(ans, curr, nums, i);
        return ans;
    }
};
