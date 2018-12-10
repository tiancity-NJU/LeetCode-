
/*

  直接相减必然超时，那么就利用二分法的思想，每次减去 divisor的 2的N次方倍，将结果表示成 2的指数相加的形式，能够缩小的O(lgn)的时间复杂度
  另外注意越界和一些特殊情况，这个问题有点类似于  string->int 之内的，要么中间变量使用 long 或者 int64_t 来避免短暂的越界或者直接利用减法的性质
  对越界进行判断

*/


class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==INT_MIN && divisor==-1)
            return INT_MAX;
        if(dividend==0) return 0;
        int flag=1;
        if(dividend>0) {dividend=-dividend; flag=-flag;}
        if(divisor>0) {divisor=-divisor;flag=-flag;}
        
        int ans=0;
        while(divisor>=dividend)
        {
            int t=divisor,sum=1;
            while(dividend-t<=t) {t=t<<1;sum=sum<<1;}
            ans+=sum;
            dividend-=t;
        }
        return flag*ans;
        
    }
};
