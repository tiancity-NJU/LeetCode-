/*
By backtracking
author: ypz
*/

class Solution {
public:
    
    void all(vector<string> &ans, string cur, int left, int right, int n) {
        if(cur.size() == 2 * n) {
            ans.push_back(cur);
        }
        if(left < n) {
            all(ans, cur + "(", left + 1, right, n);
        }
        if(right < left) {
            all(ans, cur + ")", left, right + 1, n);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        
        vector<string> result;
        if(n == 0) return result;
        all(result, "", 0, 0, n);
        return result;
        
    }
};
