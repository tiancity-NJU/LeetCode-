/*
author: ypz
由于数组循环，因此要遍历两遍
用栈存储索引
*/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        vector<int> ans(nums.size(), -1);
        if(nums.size() == 0)
            return ans;
        for(int i = 0; i < 2 * nums.size() - 1 ; i++) {
            while(s.size() && nums[s.top() % nums.size()] < nums[i % nums.size()]) {
                ans[s.top() % nums.size()] = nums[i % nums.size()];
                s.pop();
            }
            s.push(i);
        }
        return ans;
    }
};
