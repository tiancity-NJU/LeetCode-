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


/*
    先找到对应行，接着利用二分或者线性扫描即可
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        if(matrix.size()==0||matrix[0].size()==0) return false;
        int m=matrix.size(),n=matrix[0].size();
        if(matrix[0][0]>target || matrix[m-1][n-1]<target) return false;
        
        int row;
        for(row=1;row<m;row++)
        {
            if(matrix[row][0]>target) break;
        }
        row--;
        for(int i=0;i<n;i++)
        {
            if(matrix[row][i]==target) return true;
            if(matrix[row][i]>target) return false;
        }
        return false;
    }
};


/*
    或者二分（对于该题，似乎还慢一点）   特别的，对于行 也可以利用二分
*/

class Solution {
public:
    
    bool find(vector<int>&data,int target)
    {
        int left=0,right=data.size()-1;
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            if(data[mid]==target) return true;
            if(data[mid]>target) right=mid-1;
            else left=mid+1;
        }
        return false;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        if(matrix.size()==0||matrix[0].size()==0) return false;
        int m=matrix.size(),n=matrix[0].size();
        if(matrix[0][0]>target || matrix[m-1][n-1]<target) return false;
        
        int row;
        for(row=1;row<m;row++)
        {
            if(matrix[row][0]>target) break;
        }
        row--;
        return find(matrix[row],target);
    }
};
