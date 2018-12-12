
/*
  简单的位运算问题，注意顺序不能反

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
