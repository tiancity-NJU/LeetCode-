/*
author: ypz
*/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> all;
        for(int i = 0; i <= rowIndex; i++) {
            vector<int> temp(i + 1, 0);
            temp[0] = 1;
            temp[i] = 1;
            if(i > 1) {
                for(int j = 1; j <= i / 2; j++) {
                    temp[j] = all[i-1][j-1] + all[i-1][j];
                    temp[i-j] = temp[j];
                }
            }
            all.push_back(temp);
        }
        return all[rowIndex];
    }
};
