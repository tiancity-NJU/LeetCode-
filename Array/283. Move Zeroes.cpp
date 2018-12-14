
/*
  
*/



class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int count=0;
        for(auto c:nums)
            if(c==0) count++;
        
        if(count==0) return;
        int k=0;
        for(int i=0;i<nums.size();i++)
        {
            nums[k]=nums[i];
            if(nums[i]!=0)
                k++;
        }
        for(;k<nums.size();k++)
            nums[k]=0;
        
        return;
    }
};
