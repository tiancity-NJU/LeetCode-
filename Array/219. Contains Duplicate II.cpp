/*
建立一个字典，键为数值，值为该数值的索引集合。
author: ypz
*/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        bool ans = false;
        map<int, vector<int>> dict;
        for(int i = 0; i < nums.size(); i++) {
            auto it = dict.find(nums[i]);
            if(it == dict.end()) {
                vector<int> index;
                index.push_back(i);
                dict[nums[i]] = index;
            }
            else {
                dict[nums[i]].push_back(i);
                vector<int> index = dict[nums[i]];
                if(index.size() >= 2 && index[index.size()-1] - index[index.size()-2] <= k) {
                   ans = true;   
                   break;
                }
            }
        }
        return ans;
    }
};
