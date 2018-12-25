/*
  位运算问题，n每次右移一位和1进行与运算
  author: ztc
*/

class Solution {
public:
    int hammingWeight(uint32_t n) { 
        int count=0;
        for(int i=0;i<32;i++)
        {
            count+=n&1;
            n=n>>1;
        }
        return count;
    }
};

/*
    还有一种思路是每次把最低位的1变成0，然后count++， n&(n-1) 即可
    author: ztc
*/

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n) {
            n &= (n - 1);
            ++count;
        }
        return count;
    }
};


/*
author: ypz
*/

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        for(int i = 0; i < 32; i++) {
            if(n & 1 == 1) ans++;
            n = n >> 1;
        }
        return ans;
    }
};
