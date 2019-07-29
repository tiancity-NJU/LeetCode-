/*
author: ypz
借鉴一个比较好的思路，该问题实质上只有两种情况，一种是“-+-+”，另一种是“-+-+-”（两+或两-抵消为+）。
前者最大积为“-+-+”，后者最大乘积是“max(-+-+, +-+-)”。
另外注意处理中间出现0的情况。
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int ans = INT_MIN;
        int left = 1;
        int right = 1;
        for(int i = 0; i < nums.size(); i++) {
            left *= nums[i];
            right *= nums[nums.size()-1-i];
            ans = max(ans, max(left, right));
            if(left == 0)
                left = 1;
            if(right == 0)
                right = 1;
        }
        return ans;
    }
};
