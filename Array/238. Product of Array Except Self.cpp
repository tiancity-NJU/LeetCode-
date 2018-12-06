
/*

  感觉非常好的一个题目，求自身以外所有数的积，最容易想到当然是将所有数相乘，然后分别除就行，但是最大的一个问题元素如果出现 0 ，那个所有结果都是0
  并且出现除以0的情况
  
  output[i]本质上就是 nums[0-> i-1] *nums[i+1 -> end]，我们只需要用一个数组保存前n个数的积，然后从后往前计算output，并且用一个临时变量
  p的保存nums[i+1 -> end]即可，可以将辅助数组和output合并   output[i]即 nums[0->i-1]  的积

*/




class Solution {
    
 
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        vector<int>ans;
        int start=1;
        
        
        for(int i=0;i<nums.size();i++)
        {
            ans.push_back(start);
            start=start*nums[i];
        }
        
        start=1;  //右边乘积
        for(int i=nums.size()-1;i>=0;i--)
        {
            ans[i]=ans[i]*start;
            start=start*nums[i];
        }
        
        return ans;
    }
};
