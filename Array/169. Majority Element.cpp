/*
采用字典存储各个元素出现的次数。
author: ypz
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> dict;
        for(int i = 0; i < nums.size(); i++) {
            auto it = dict.find(nums[i]);
            if(it != dict.end()) it -> second += 1;
            else dict[nums[i]] = 1;
        }
        map<int, int>::iterator iter;
        int max_num = 0;
        for(auto it = dict.begin(); it != dict.end(); it++) {
            if(it -> second > max_num) {
                max_num = it -> second;
                iter = it;
            }
        }
        return iter -> first;
    }
};
