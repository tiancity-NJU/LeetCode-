
/*

    主要就是发现规律，分以下几步：从右往左找到第一个降序元素，假设位置为pos，从pos+1到end寻找大于nums[pos]的最小值，交换；最后
    对pos后面的内容升序排序。
    特别要注意处理从右到左一直升序的情况，直接反转整个数组
    代码还有可以优化的地方

*/


class Solution {
public:
    void nextPermutation(vector<int>& nums) {
     
        int pos;
        for(pos=nums.size()-2;pos>=0;pos--)
        {
            if(nums[pos]<nums[pos+1]) break;
        }
        if(pos==-1) return reverse(nums.begin(),nums.end());
        
        int newpos=pos+1,newvalue=nums[pos+1];
        for(int i=pos+1;i<nums.size();i++)
        {
            if(nums[i]>nums[pos]&&nums[i]<newvalue)
            {
                newvalue=nums[i];
                newpos=i;
            }
        }
        int tmp=nums[pos];
        nums[pos]=nums[newpos];
        nums[newpos]=tmp;
        sort(nums.begin()+pos+1,nums.end());
        
    
    }
};
