

/*
  正常操作的话暴力穷举的话肯定超时，一般这种对数组一个比较复杂性质的题目基本都要先排个序，O(nlgn) 的复杂度往往低于题目的复杂度
  
  想办法控制在O(n2) 的时间范围
  
  先对i从0开始遍历，然后利用两个指针从 i+1 ---- n 左右逼近计算，注意跳过重复元素
  这样能将时间压缩在平方范围内。


*/



class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        
        int i=0;
        while(i<nums.size())
        {
            int goal=0-nums[i];
            int left=i+1,right=nums.size()-1;
            while(left<right)
            {
                int tmp=nums[left]+nums[right];
                if(tmp==goal)
                {
                    vector<int> sit;
                    sit.push_back(nums[i]);
                    sit.push_back(nums[left]);
                    sit.push_back(nums[right]);
                    ans.push_back(sit);
                    while(left<right&&nums[left]==nums[left+1]) left++;
                    while(left<right&&nums[right]==nums[right-1]) right--;
                    left++;
                    right--;
                }
                else
                {
                    if(tmp<goal) left++;
                    else right--;
                }
            }
            while(i<nums.size()&&nums[i]==nums[i+1]) i++;
            i++;
        }
        return ans;
    }
};
