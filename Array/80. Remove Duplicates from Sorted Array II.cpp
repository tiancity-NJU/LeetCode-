/*
author: ypz
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 2) return nums.size();
        else {
            for(int i = 2; i < nums.size(); ) {
                if(nums[i] == nums[i-2] && nums[i] == nums[i-1]) nums.erase(nums.begin() + i);
                else i++;
                
            }
            return nums.size();
        }
    }
};
