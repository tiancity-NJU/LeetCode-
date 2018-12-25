/*
f(n) = n/5 + f(n/5);
author: ypz
*/

class Solution {
public:
    int trailingZeroes(int n) {
        if(n < 5) return 0;
        if(n < 10) return 1;
        else return n/5 + trailingZeroes(n/5);
    }
};
