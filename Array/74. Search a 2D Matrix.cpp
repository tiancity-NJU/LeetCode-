/*
二分法查找，getValue函数用于通过索引值获取元素值
author: ypz
*/

class Solution {
public:
    int getValue(vector<vector<int>>& matrix, int x, int n) {
        int i = x / n;
        int j = x % n;
        return matrix[i][j];
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return false;
        int m = matrix.size();
        int n = matrix[0].size();
        int length = m * n;
        int left = 0;
        int right = length - 1;
        while(left <= right) {
            int mid = (left + right) / 2;
            if(getValue(matrix, mid, n) == target) return true;
            else if(getValue(matrix, mid, n) > target) right = mid - 1;
            else left = mid + 1;
        }
        return false;
    }
};
