/*
    首先看到这个问题，第一个简单的想法当然是O(nlgn) 的排序再搭配一次扫描，本想只是尝试一下，没想到这个答案就已经打败97%，但是严格来说是不符合
    题意的，因此我们需要尝试另外的方法
*/



class Solution {
public:
    int maximumGap(vector<int>& nums) {
        
        if(nums.size()<2) return 0;
        sort(nums.begin(),nums.end());
        
        int gap=0;
        for(int i=1;i<nums.size();i++)
            gap=max(gap,nums[i]-nums[i-1]);
        
        return gap;
        
    }
};


/*

  想了半天并没有什么其他的思路，看了别人的方法，主要是使用了桶排序的策略，具体还不是非常明白

*/

class Solution {
public:
    int maximumGap(vector<int>& nums) {
                
        for (int i=0; i<kIntSize; ++i) countingSort(nums,i);        
        int maxgap = 0;
        for (int i=0; i<(int)(nums.size())-1;++i) maxgap=max(maxgap,nums[i+1]-nums[i]);
        return maxgap;
    }    
    
private:
    void countingSort(vector<int> &nums, int byteidx) {
        vector<int> buckets(1<<kByteSize,0);
        vector<int> result(nums.size(),0);
        for (const auto n : nums) ++buckets[applyByteMask(n,byteidx)];
        for (int i=1; i<buckets.size(); ++i) buckets[i]+=buckets[i-1];
        for (int i=nums.size()-1; i>=0; --i) result[--buckets[applyByteMask(nums[i],byteidx)]]=nums[i];
        swap(nums,result);        
    }
    
    int applyByteMask(int n, int byteidx) {
        static const int bytemask = (1<<kByteSize)-1;
        return (n>>(byteidx*kByteSize))&bytemask;
    }
    
    static const int kIntSize  = sizeof(int);      
};
