/*
By backtracking.
author: ypz
*/

class Solution {
public:
    void backTracking(vector<vector<int>> &ans, vector<int> &curr, vector<int> &candidate, int k) {
        if(curr.size() == k) ans.push_back(curr);
        else {
            for(int i = 0; i < candidate.size(); i++) {
                vector<int> curr_temp(curr);
                vector<int> candidate_temp(candidate);
                curr_temp.push_back(candidate[i]);
                candidate_temp.erase(candidate_temp.begin(), candidate_temp.begin() + i + 1);
                backTracking(ans, curr_temp, candidate_temp, k);
            }
        }
    }
        
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> curr;
        vector<int> candidate(n, 0);
        for(int i = 0; i < n; i++) candidate[i] = i + 1;
        backTracking(ans, curr, candidate, k);
        return ans;
    }
};
