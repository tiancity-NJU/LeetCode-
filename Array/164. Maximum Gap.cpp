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
    比较难的一题，利用桶排序的思想，按照取值范围构建一个个范围为(max-min)/size()的桶，并且最大值不可能小于桶内差异，如果等于的话即使等差数列
    基于这一点，每个桶记录该范围内的最大值和最小值，每次相邻的桶之间比较即可
    

*/


class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        int maxNum = nums[0];
        int minNum = nums[0];
        for (int i : nums) {
            maxNum=max(maxNum,i);
            minNum=min(minNum,i);
        }
       
        int len = (maxNum - minNum) / nums.size() + 1;
        vector<vector<int>> buckets((maxNum - minNum) / len + 1);
        
        for(int i=0;i<nums.size();i++)
        {
            int pos=(nums[i]-minNum)/len;
            if(buckets[pos].empty())
            {
                buckets[pos].push_back(nums[i]);
                buckets[pos].push_back(nums[i]);
            }
            else
            {
                buckets[pos][0]=min(buckets[pos][0],nums[i]);
                buckets[pos][1]=max(buckets[pos][1],nums[i]);                
            }
        }
        int gap=0;
        int pre=0;
        int i=0;
        for(i=0;i<(maxNum-minNum)/len;i++)
        {
            if(!buckets[i].empty())
            {
                gap=buckets[i][1]-buckets[i][0];
                break;
            }
        }
        pre=i;
        for(;i<(maxNum-minNum)/len+1;i++)
        {
            if(!buckets[i].empty())
            {
                gap=max(gap,buckets[i][0]-buckets[pre][1]);
                pre=i;
            }
        }
        return gap;
        
    }
};
