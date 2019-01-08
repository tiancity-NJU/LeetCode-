/*
  参考，用空间换时间，二维DP数组

*/


class Solution {
public:
    int minDistance(string word1, string word2) {
        int M = word1.size();
        int N = word2.size();
        
        if (!M) return N;
        if (!N) return M;
        
        int T[M+1][N+1];
        
        T[0][0] = 0;
        for (int j = 1; j <= N; ++j)
            T[0][j] = j;
        for (int i = 1; i <= M; ++i)
            T[i][0] = i;
        
        int insert_cost = 1, delete_cost = 1, replace_cost = 1;
        for (int i = 1; i <= M; ++i) {
            for (int j = 1; j <= N; ++j) {
                if (word1[i-1] == word2[j-1]) {
                    T[i][j] = min (T[i-1][j-1], 
                                   min(T[i-1][j] + delete_cost, T[i][j-1] + insert_cost));
                } else {
                    T[i][j] = min(T[i-1][j-1] + replace_cost,
                                  min(T[i-1][j] + delete_cost, T[i][j-1] + insert_cost));
                    
                }
            }
        }
        
        return T[M][N];
    }
};

/*
    简化一下就是
*/
class Solution {
public:
    int minDistance(string word1, string word2) {
    
        int m=word1.size(),n=word2.size();
        if(m==0 || n==0)
            return m+n;
        
        int dp[m+1][n+1];
        for(int i=0; i<m+1; i++){
            dp[i][0] = i;
        }
        for(int i=0; i<n+1; i++){
            dp[0][i] = i;
        }
        
        for(int i=1; i< m+1; i++){
            for(int j = 1; j< n+1; j++){
                if(word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1])) + 1;
            }
        }
        return dp[m][n];
    }
};
