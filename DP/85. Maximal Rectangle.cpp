
/*
    暴力法，有点类似85题，利用一个height记录一个最大高度，然后依次扫描在height[j] 之前的面积，只能打败5.6%的答案
*/


class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0) {
            return 0;
        }
        int m = matrix.size(), n = matrix[0].size();
        int ret=0;
        vector<int>height(n,0);
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]=='0')
                {
                    height[j]=0;
                    continue;
                }
                height[j]++;
                int minHeight=height[j];
                for(int k=j;k>=0;k--)
                {
                    minHeight=min(minHeight,height[k]);
                    ret=max(ret,(j-k+1)*minHeight);
                }
            }
        }
        return ret;
    }
};

/*
  设想一下优化思路，只需要加入一条判断，能让计算提前终止(minHeight==0)  通过这一行代码，能够将排名从5.6%上升到32.69%
*/
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0) {
            return 0;
        }
        int m = matrix.size(), n = matrix[0].size();
        int ret=0;
        vector<int>height(n,0);
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]=='0')
                {
                    height[j]=0;
                    continue;
                }
                height[j]++;
                int minHeight=height[j];
                for(int k=j;k>=0;k--)
                {
                    minHeight=min(minHeight,height[k]);
                    if(minHeight==0) break;
                    ret=max(ret,(j-k+1)*minHeight);
                }
            }
        }
        return ret;      
    }
};


/*
    最后当然还是DP的方法  https://blog.csdn.net/magicbean2/article/details/68486631
    重点是维护一个left right height 数组，左闭右开    每一次算的 j  都是对应i行为底，j左右延伸成的矩阵的最大值
*/


class Solution {
public:
 
    int maximalRectangle(vector<vector<char> > &matrix) {
        
	    if(matrix.size()==0) return 0;
        int m=matrix.size(),n=matrix[0].size();
        vector<int>left(n,0),right(n,n),height(n,0);
        int ans=0;
        for(int i=0;i<m;i++)
        {
            int curleft=0;
            int curright=n;
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]=='1')
                {
                    height[j]=height[j]+1;
                    left[j]=max(left[j],curleft);
                }
                else
                {
                    height[j]=0;
                    left[j]=0;
                    curleft=j+1;
                }
            }
            for(int j=n-1;j>=0;j--)
            {
                if(matrix[i][j]=='1')
                {
                    right[j]=min(right[j],curright);
                }
                else 
                {
                    right[j]=n;
                    curright=j;
                }
            }
            for(int j=0;j<n;j++)
                ans=max(ans,(right[j]-left[j])*height[j]);
        }
        return ans;
    }
};

