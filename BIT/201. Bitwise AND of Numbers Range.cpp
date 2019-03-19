

/*
  看上去比较变态，但是只要m!=n 最低位的 AND必定是0，同理通除以10以后最低位不相等的话，即第二低位也是0，以此类推直到 m==n

*/

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int time=0;
        while(m!=n)
        {
            m=m>>1;
            n=n>>1;
            time++;
        }
        return m<<time;
        
        
    }
};
