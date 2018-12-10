/*
By backtracking
首先将candidates按从小到大排序，与39题不同点在于由于每个元素只能使用一次，因此进入下一次回溯前需删除当前元素。
注意易错点为可能会出现重复结果，需要在每次for循环时，避免相同元素作为起始点。
author: ypz
*/

class Solution {
public:
    
    void backTracking(vector<vector<int>>& ans, vector<int>& candidates, vector<int>& cur, int temp, int target) {
        if(temp == target) {
            ans.push_back(cur);
            return;
        }
        else if(temp > target || candidates.size() == 0) return;
        else {
            for(int i = 0; i < candidates.size(); i++) {
                if(i != 0 && candidates[i] == candidates[i - 1]) continue;
                vector<int> list(candidates);
                vector<int> curr(cur);
                int tmp = temp;
                if(i != 0) list.erase(list.begin(), list.begin() + i);
                curr.push_back(list[0]);
                tmp += list[0];
                list.erase(list.begin());
                backTracking(ans, list, curr, tmp, target);
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        if(candidates.size() == 0) return ans;
        vector<int> cur;
        int temp = 0;
        sort(candidates.begin(), candidates.end());
        backTracking(ans, candidates, cur, temp, target);
        return ans;
    }
};
