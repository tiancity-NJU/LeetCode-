/*
By backtracking
与第46题类似，只需注意每次回溯前避免起始元素的重复即可
author: ypz
*/
class Solution {
public:
    void backTracking(vector<vector<int>> &ans, vector<int> &curr, vector<int> &nums) {
        if(nums.size() == 0) ans.push_back(curr);
        for(int i = 0; i < nums.size(); i++) {
            if(i != 0 && nums[i] == nums[i - 1]) continue;
            curr.push_back(nums[i]);
            vector<int> temp = nums;
            temp.erase(temp.begin() + i);
            backTracking(ans, curr, temp);
            curr.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size() == 0) return ans;
        else if(nums.size() == 1) ans.push_back(nums);
        else {
            vector<int> curr;
            sort(nums.begin(), nums.end());
            backTracking(ans, curr, nums);
        }
        return ans;
    }
};
