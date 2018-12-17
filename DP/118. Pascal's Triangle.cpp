/*
author: ypz
*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        if(numRows == 0) return ans;
        for(int i = 0; i < numRows; i++) {
            vector<int> temp(i + 1, 0);
            temp[0] = 1;
            temp[i] = 1;
            if(i > 1) {
                for(int j = 1; j <= i / 2; j++) {
                    temp[j] = ans[i-1][j-1] + ans[i-1][j];
                    temp[i-j] = temp[j];
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
