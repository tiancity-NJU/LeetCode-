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


/*
    显然可以发现，每次都是沿着顺时针方向改变，并且步数是  n n-1 n-1 n-2 n-2 ....1 1
*/
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<int>tmp(n,0);
        vector<vector<int>>ans(n,tmp);
        
        int direct[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

        int step=n;
        int num=1;
        int i=0,j=0,k=0;
        int x=0,y=n-1,d=1;
        for(i=0;i<step;i++)
            ans[0][i]=num++;
        
        step--;
        int remain=n*n-n;
        while(step)
        {
            for(j=0;j<2;j++)
            {
                for(k=0;k<step;k++)
                {
                    x+=direct[d][0];
                    y+=direct[d][1];
                    ans[x][y]=num++;
                }
                d=(d+1)%4;
            }
            step--;
        }
        return ans;
    }
};
