/*
借鉴网上的思路https://www.cnblogs.com/lichen782/p/leetcode_Jump_Game_II.html
扫描数组，以确定当前最远能覆盖的节点，并更新这个覆盖范围，直到当前的索引超过了上一次算出的覆盖范围，更新步数。
即争取每跳最远的greedy。
author: ypz
*/
class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() <= 1) return 0;
        int last = 0;
        int cur = 0;
        int step = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(i <= last) {
                cur = max(cur,  i + nums[i]);
            }
            else{
                step++; 
                last = cur;
                cur = max(cur,  i + nums[i]);
            }
            
        }
        return step;
    }
};
