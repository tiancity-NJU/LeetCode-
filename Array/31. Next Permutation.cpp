class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        /*
        author: ypz
        1. 从后向前数，找到第一个非升序的数num1；若不存在，翻转数组；
        2. 从后向前数，找到第一个比num1大的数num2，交换num1与num2；
        3. 将num2后的数逆序排序；
        */
        
        if(nums.size() < 2) return;
        int length = nums.size();
        int index1 = nums.size() - 1;
        for(index1; index1 > 0; index1--) {
            if(nums[index1 - 1] < nums[index1]) {
                index1--;
                break;
            }
        }
        if(index1 == 0 && nums[index1] > nums[index1 + 1]) {
            reverse(nums.begin(), nums.end());
            return;
        }
        int index2 = nums.size() - 1;
        for(index2; index2 > index1; index2--) {
            if(nums[index2] > nums[index1]) {
                break;
            }
        }
        swap(nums[index1], nums[index2]);
        reverse(nums.begin() + index1 + 1, nums.end());
        return;
    }
};
