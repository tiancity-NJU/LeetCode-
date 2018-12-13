/*
By BckTracking.
注意外层for循环必须执行完成，不论flag值如何。
author: ypz
*/

class Solution {
public:
    
    void backTracking(vector<vector<string>>& ans, vector<int>& list, vector<string>& cur, int index, int n) {
        if(index == n) {
            ans.push_back(cur);
            return;
        }
        for(int i = 0; i < n; i++) {
            vector<int> list_copy(list);
            list_copy.push_back(i);
            int flag = 0;
            for(int j = 0; j < index; j++) {
                if(list[j] == i || abs(j - index) == abs(list[j] - i)) {
                    flag = 1;
                    break;
                }
            }
            if(flag == 0) {
                vector<string> cur_copy(cur);
                string temp(n, '.');
                temp[i] = 'Q';
                cur_copy.push_back(temp);
                backTracking(ans, list_copy, cur_copy, index + 1, n);
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<int> list;
        vector<string> cur;
        backTracking(ans, list, cur, 0, n);
        return ans;
    }
};
