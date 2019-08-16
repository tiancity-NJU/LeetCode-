
/*
  author：ztc
  和最大子串和只要保留当前最大值不同，乘法最大需要保留最大最小，因为很可能最小值乘以负数就会变成最大值，所以只需要
  维护两个变量tempMin，tempMax，这在DP的O(n)空间的基础上进一步缩小了空间代价（因为只和前后有关）
*/


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size()==0) return 0; 
        
        int currMin=nums[0]; 
        int currMax=nums[0]; 
        int maxProduct = currMax;
        
        for (int i = 1; i < nums.size(); i++)
        {
            int num=nums[i];
            int tempMin;
            int tempMax;
            // Either multiply by num, or start over 
            if(num>0)
            {
            tempMin = min(currMin*num,num); 
            tempMax = max(currMax*num,num); 
            }
            else{
            // Check if sign change improves min/max
            tempMin=min(num,currMax*num);
            tempMax=max(num,currMin*num);
            }
            // Update
            currMin=tempMin;
            currMax=tempMax;
            
            maxProduct=max(maxProduct,currMax);
        }
        
        return maxProduct;
    }
};


/*
author: ypz
借鉴一个比较好的思路，该问题实质上只有两种情况，一种是“-+-+”，另一种是“-+-+-”（两+或两-抵消为+）。
前者最大积为“-+-+”，后者最大乘积是“max(-+-+, +-+-)”。
另外注意处理中间出现0的情况。
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int ans = INT_MIN;
        int left = 1;
        int right = 1;
        for(int i = 0; i < nums.size(); i++) {
            left *= nums[i];
            right *= nums[nums.size()-1-i];
            ans = max(ans, max(left, right));
            if(left == 0)
                left = 1;
            if(right == 0)
                right = 1;
        }
        return ans;
    }
};
