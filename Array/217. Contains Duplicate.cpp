/*
author: ypz
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        bool ans = false;
        set<int> list;
        for(int i = 0; i < nums.size(); i++) {
            auto it = list.find(nums[i]);
            if(it == list.end()) list.insert(nums[i]);
            else {
                ans = true;
                break;
            }
        }
        return ans;
    }
};
