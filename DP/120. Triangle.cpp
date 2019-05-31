
/*
    author: ztc
    挺好的一个题目，包括前面的很多问题，正向求解会有难度，利用反向的扫描会变得更加简单，这题可以看作不同支流汇聚的问题，我们可以设置一个和triangle
    一样大小的成梯度的DP数组，其中 DP[i][j]代表从下往上到第i层第j个数的最短路径，这种问题同样可以用DFS，但是肯定很慢
*/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size()==0||triangle[0].size()==0) return 0;
        vector<int>DP(triangle.back());
        for(int i=triangle.size()-2;i>=0;i--)
        {
            for(int j=0;j<triangle[i].size();j++)
            {
                DP[j]=min(DP[j],DP[j+1])+triangle[i][j];
            }
        }
        return DP[0];
    }
};

/*
    还有一种暴力的解法，就是使用DFS，但是这样会超时
*/

class Solution {
public:
    void DFS(vector<vector<int>>&triangle,int pos,int s,int e,int& sum,int& res)
    {
        if(s==e)
        {
            sum+=min(triangle[e][pos],triangle[e][pos+1]);
            res=min(res,sum);
            sum-=min(triangle[e][pos],triangle[e][pos+1]);
            return;
        }
        sum+=triangle[s][pos];
        DFS(triangle,pos,s+1,e,sum,res);
        sum-=triangle[s][pos];
        sum+=triangle[s][pos+1];
        DFS(triangle,pos+1,s+1,e,sum,res);
        sum-=triangle[s][pos+1];
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size()==0||triangle[0].size()==0) return 0;
        if(triangle.size()==1) return triangle[0][0];
        int res=INT_MAX;
        int sum=triangle[0][0];
        DFS(triangle,0,1,triangle.size()-1,sum,res);
        return res;
    }
};


/*
author: ypz
*/

// 方法一：自底向上，dp为二维数组

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size() == 1) 
            return triangle[0][0];
        vector<vector<int>> dp(triangle.size(), vector<int>(triangle.size(), 0));
        dp[triangle.size()-1] = triangle[triangle.size()-1];
        for(int i = triangle.size() - 2; i >= 0; i--) {
            for(int j = 0; j <= i; j++) {
                dp[i][j] = min(dp[i+1][j], dp[i+1][j+1]) + triangle[i][j];
            }
        }
        return dp[0][0];
    }
};


// 方法二：自底向上，dp为一维数组，每一层循环对其更新

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> dp(triangle.back());
        for(int i = triangle.size() - 2; i >= 0; i--) {
            for(int j = 0; j <= i; j++)
                dp[j] = triangle[i][j] + min(dp[j], dp[j+1]);
        }
        return dp[0];
    }
    
};
