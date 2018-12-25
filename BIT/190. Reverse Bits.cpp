
/*
  简单的位运算问题，注意顺序不能反
  author: ztc
*/

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        
        uint32_t ans=0;
        for(int i=0;i<32;i++)
        {
            ans=ans<<1;
            ans+=n&1;
            n=n>>1;
        }
        return ans;
    }
};


/*
author: ypz
*/

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        bitset<32> n_bitset(n);
        bitset<32> ans;
        for(auto i = 0; i < 32; i++) ans[i] = n_bitset[32 - i - 1];
        return ans.to_ulong();
    }
};
