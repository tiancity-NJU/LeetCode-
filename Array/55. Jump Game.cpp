/*
与第45题同样的思路。
author: ypz
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int last = 0;
        int curr = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(i <= last) curr = max(curr, i + nums[i]);
            else {
                last = curr;
                curr = max(curr, i + nums[i]);
            }
            if(curr >= nums.size() - 1) return true;            // 与下一行不可颠倒，例子:[0]
            if(curr == i) return false;                         // 与上一行不可颠倒，例子:[0]
        }
    }
};
