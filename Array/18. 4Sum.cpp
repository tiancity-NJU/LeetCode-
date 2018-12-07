/*

  套路和3sum一样      外面再套一层循环构成  1+3 sum   注意碰到相同的要跳过去

*/



class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector<vector<int>>ans;
        if(nums.size()<4) return ans;
        
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size()-3;i++)
        {
            if(i!=0&&nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<nums.size()-2;j++)
            {
                if(j!=i+1&&nums[j]==nums[j-1]) continue;
                
                int goal=target-nums[i]-nums[j];
                int left=j+1,right=nums.size()-1;
                while(left<right)
                {
                    int tmp=nums[left]+nums[right];
                    if(tmp==goal)
                    {
                        vector<int>one;
                        one.push_back(nums[i]);
                        one.push_back(nums[j]);
                        one.push_back(nums[left]);
                        one.push_back(nums[right]);
                        ans.push_back(one);
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
            }
        }
        return ans;
    }
};
