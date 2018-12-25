/*
两个相同的数进行按位异或运算结果一定为0，一个数与0按位异或结果即为该数本身
数组中所有数按位异或,留下的为single number
author: ypz
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = nums[0];
        for(int i = 1; i < nums.size(); i++) result ^= nums[i];
        return result;
    }
};
