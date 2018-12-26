/*
author: ypz
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        else if(nums.size() == 1) return nums[0];
        else if(nums.size() == 2) return max(nums[0], nums[1]);
        vector<int> dp(nums.size(), 0);
        for(int i = 0; i < nums.size(); i++) {
            if(i == 0) dp[i] = nums[i];
            else if(i == 1) dp[i] = max(nums[i], nums[i-1]);
            else dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }
        return dp[nums.size()-1];
    }
};
