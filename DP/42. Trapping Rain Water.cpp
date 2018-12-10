/*
借鉴Soultion中Approach 2: Dynamic Programming
author: ypz
*/

class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() <= 2) return 0;
        int ans = 0;
        vector<int> right(height.size());
        vector<int> left(height.size());
        right[0] = height[0];
        left[height.size() - 1] = height[height.size() - 1];
        int max_right = 0;
        int max_left = 0;
        for(int i = 1; i < height.size(); i++) right[i] = max(right[i - 1], height[i]);
        for(int j = height.size() - 2; j >= 0 ; j--) left[j] = max(left[j + 1], height[j]);
        for(int k = 0; k < height.size(); k++) ans += min(right[k], left[k]) - height[k];
        return ans;
    }
};
