/*
按字典存储即可
author: ypz
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> ans;
        vector<vector<string>> result;
        for(string s: strs) {
            string s_copy(s);
            sort(s_copy.begin(), s_copy.end());
            ans[s_copy].push_back(s);
        }
        for(auto t = ans.begin(); t != ans.end(); t++) {
            result.push_back(t -> second);
        }
        return result;
    }
};
