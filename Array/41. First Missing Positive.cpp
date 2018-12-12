

/*

   脑洞大开的题，大于数组长度的值肯定不必纳入考虑范畴，只需要针对在len范围内的数组进行操作，in-place的方法，将数到的数转换成下标，将对应位置的数
   变成负数，这样最后扫描一遍数组发现一个大于0的，即为缺失的最小值，同理从右往左就是缺失的最大值（len范围内的）

*/




class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        int len=nums.size();
        
        for(int i=0;i<nums.size();i++)
        {
            nums[i]=nums[i]<=0?len+1:nums[i];
        }
        
        for(int i=0;i<nums.size();i++)
        {
            if(abs(nums[i])>len) continue;
            int pos=abs(nums[i])-1;
            nums[pos]=-abs(nums[pos]);
        }
        
  
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>0)
                return i+1;
        }
        return len+1;
        
    }
};
