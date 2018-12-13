/*
二分搜索。注意sqrt(n) < n/2 + 1。注意边界。
author: ypz
*/
class Solution {
public:
    int mySqrt(int x) {
        if(x == 1) return 1;
        long long left = 0;
        long long right = x/2 + 1;
        while(left <= right) {
            long long mid = (left + right) / 2;
            if(mid * mid == x) return mid;
            else if(mid * mid > x) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return right;
    }
};
