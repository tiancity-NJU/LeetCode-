
/*

   直接利用二分总是出错，借鉴了别人的方法，主要两个核心问题就是终止条件以及左右边界的确定
   author:ztc

*/


// Forward declaration of isBadVersion API.
bool isBadVersion(int version);
class Solution {
public:
    int firstBadVersion(int n) 
    {
        int64_t good=0, bad=n;
        
        while (bad-good > 1)
        {
            int64_t mid = (bad+good)/2;
            if (isBadVersion(mid))
                bad = mid;
            else
                good = mid;
        }

        return bad;
    }
};



/*

   

*/
