/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */

/*
方法一：暴力
author：ypz
*/

class NumArray {
private:
    vector<int> data;
public:
    NumArray(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++)
            data.push_back(nums[i]);
    }
    
    int sumRange(int i, int j) {
        int sum = 0;
        for(int k = i; k <= j; k++) 
            sum += data[k];
        return sum;
    }
};

/*
方法二：动态规划，注意边界条件
author: ypz
*/

class NumArray {
private:
    vector<int> dp = {0};
public:
    NumArray(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            dp.push_back(sum);
        }
    }
    
    int sumRange(int i, int j) {
        return dp[j+1] - dp[i];
    }
};
