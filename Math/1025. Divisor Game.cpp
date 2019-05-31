// 可以证明，偶数必赢，奇数必输
class Solution {
public:
    bool divisorGame(int N) {
        if(N % 2 == 0) return true;
        else return false;
    }
};
