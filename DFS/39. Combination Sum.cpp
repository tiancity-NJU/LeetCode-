class Solution {
public:

    /*
    By backtracking
    注意元素可以重复使用，因此在进入下一次回溯前不要删除当前元素。
    author: ypz
    */
    
    void backTracking(vector<vector<int>>& ans, vector<int>& candidates, vector<int>& cur, int temp, int target) {
        if(temp == target) {
            ans.push_back(cur);
            return;
        }
        else if(temp > target || candidates.size() == 0) return;
        else {
            for(int i = 0; i < candidates.size(); i++) {
                vector<int> list(candidates);
                vector<int> curr(cur);
                int tmp = temp;
                if(i != 0) list.erase(list.begin(), list.begin() + i);
                curr.push_back(list[0]);
                tmp += list[0];
                backTracking(ans, list, curr, tmp, target);
            }
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        if(candidates.size() == 0) return ans;
        vector<int> cur;
        int temp = 0;
        backTracking(ans, candidates, cur, temp, target);
        return ans;
    }
};
