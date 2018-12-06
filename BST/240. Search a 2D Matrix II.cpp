
/*
  
  直接搜索的话肯定超时，因此要找到点其他的方法缩小搜索范围，以对角线元素n为例，每次判断target在不在n所在的行和列的范围，没有的话直接跳过，因为最小值
  为a[i][j] 最大值即为 a[h][j] or a[i][w] 


*/







class Solution {
public:
    
    
    bool serarch(vector<vector<int>>&matrix,int i,int j,int h,int w,int target)
    {
        for(int k=j;k<=w;k++)
            if(matrix[i][k]==target) return true;
        
        for(int k=i;k<=h;k++)
            if(matrix[k][j]==target) return true;
        
        return false;
    }
    
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        
        if(matrix.size()==0 || matrix[0].size()==0) return false;
        
        if(target<matrix[0][0]) return false;
        if(target>matrix.back().back()) return false;
        
        
        int i=0,j=0;
        int h=matrix.size()-1,w=matrix[0].size()-1;
        
        bool find=false;
        for(;i<=h&&j<=w;i++,j++)
        {
            if(matrix[i][j]<=target&&max(matrix[i][w],matrix[h][j])>=target)
            {
                  if(serarch(matrix,i,j,h,w,target)) find=true;
            }
        }
        
        return find;
        
        
    }
};
