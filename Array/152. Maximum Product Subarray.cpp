
/*
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
