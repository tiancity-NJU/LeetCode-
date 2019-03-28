/*
author: ypz
*/
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int num = 0;
        int row = board.size();
        int col = board[0].size();
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                int flag1 = 0, flag2 = 0;
                if(i >= 1 && board[i-1][j] == 'X') flag1 = 1;
                if(j >= 1 && board[i][j-1] == 'X') flag2 = 1;
                if(flag1 != 1 && flag2 != 1 && board[i][j] == 'X') num++;
            }
        }
        return num;
    }
};
