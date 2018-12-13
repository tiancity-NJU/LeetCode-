/*
与第54题相同的思路。
author: ypz
*/

class Solution {
public:    
    vector<vector<int>> generateMatrix(int n) {
        vector<int> temp(n, 0);
        vector<vector<int>> ans(n, temp);
        int row = n;
        int col = n;
        int length = 1;
        int i = 0;
        int j = 0;
        row += 1;
        while(length <= n * n) {
            for(int m = 0; m < row - 1; m++) {
                ans[i][j] = length;
                length++;
                j++;
            }
            j--;
            i++;
            if(length > n * n) break;
            row--;
            for(int m = 0; m < col - 1; m++) {
                ans[i][j] = length;
                length++;
                i++;
            }
            i--;
            j--;
            if(length > n * n) break;
            col--;
            for(int m = 0; m < row - 1; m++) {
                ans[i][j] = length;
                length++;
                j--;
            }
            j++;
            i--;
            if(length > n * n) break;
            row--;
            for(int m = 0; m < col - 1; m++) {
                ans[i][j] = length;
                length++;
                i--;
            }
            i++;
            j++;
            if(length > n * n) break;
            col--;   
        }
        return ans;
    }
};
