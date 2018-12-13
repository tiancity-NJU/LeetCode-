/*
按顺序遍历即可。
author: ypz
*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if(matrix.size() == 0) return ans;
        int row = matrix[0].size();
        int col = matrix.size();
        int length = col * row;
        int i = 0;
        int j = 0;
        row += 1;
        while(length > 0) {
            for(int m = 0; m < row - 1; m++) {
                ans.push_back(matrix[i][j]);
                length--;
                j++;
            }
            j--;
            i++;
            if(length == 0) break;
            row--;
            for(int m = 0; m < col - 1; m++) {
                ans.push_back(matrix[i][j]);
                length--;
                i++;
            }
            i--;
            j--;
            if(length == 0) break;
            col--;
            for(int m = 0; m < row - 1; m++) {
                ans.push_back(matrix[i][j]);
                length--;
                j--;
            }
            j++;
            i--;
            if(length == 0) break;
            row--;
            for(int m = 0; m < col - 1; m++) {
                ans.push_back(matrix[i][j]);
                length--;
                i--;
            }
            i++;
            j++;
            if(length == 0) break;
            col--;   
        }
        return ans;
    }
};
