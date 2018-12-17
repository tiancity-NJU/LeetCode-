



/*
  典型DFS，时间复杂度没得法子减，空间上图方便，利用了一个mask，表示不能走或者走过的路，然后朝着四个方向深度遍历
  但是完全可以将走过的位置换成一个特殊的字符，深度以后用string word对应位置的字符复原即可
*/


class Solution {
public:
    
    void dfs(vector<vector<char>>&board,vector<vector<int>>&mask,int x,int y,string& remain,bool& find)
    {
        if(board[x][y]!=remain[0]) return;
        
        if(board[x][y]==remain[0]&&remain.size()==1) {find=true;return;}
        
            mask[x][y]=1;
            string rem=remain.substr(1);
            if(x+1<board.size()&&!mask[x+1][y]) dfs(board,mask,x+1,y,rem,find);
            if(find) return;
            if(x-1>=0&&!mask[x-1][y]) dfs(board,mask,x-1,y,rem,find);
            if(find) return;
            if(y+1<board[0].size()&&!mask[x][y+1]) dfs(board,mask,x,y+1,rem,find);
            if(find) return;
            if(y-1>=0&&!mask[x][y-1]) dfs(board,mask,x,y-1,rem,find);
            if(find) return;
            mask[x][y]=0;
        
    }
    
    
    bool exist(vector<vector<char>>& board, string word) {
        vector<int> tmp(board[0].size(),0);
        vector<vector<int>>mask(board.size(),tmp);
        bool find=false;
        
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]==word[0])
                {
                    dfs(board,mask,i,j,word,find);
                    if(find) return true;
                }
            }
        }
        return false;
        
    }
};
