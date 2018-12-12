class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        /*
        author: ypz
        1. 从后向前数，找到第一个非升序的数num1；若不存在，翻转数组；
        2. 从后向前数，找到第一个比num1大的数num2，交换num1与num2；
        3. 将num2后的数逆序排序；
        */
        
        if(nums.size() < 2) return;
        int length = nums.size();
        int index1 = nums.size() - 1;
        for(index1; index1 > 0; index1--) {
            if(nums[index1 - 1] < nums[index1]) {
                index1--;
                break;
            }
        }
        if(index1 == 0 && nums[index1] > nums[index1 + 1]) {
            reverse(nums.begin(), nums.end());
            return;
        }
        int index2 = nums.size() - 1;
        for(index2; index2 > index1; index2--) {
            if(nums[index2] > nums[index1]) {
                break;
            }
        }
        swap(nums[index1], nums[index2]);
        reverse(nums.begin() + index1 + 1, nums.end());
        return;
    }
};




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
