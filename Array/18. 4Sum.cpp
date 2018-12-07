/*
  套路和3sum一样      外面再套一层循环构成  1+3 sum   注意碰到相同的要跳过去
  另外可以加一下限制条件，跳过不可能情况，进一步缩短运行时间，例如排序后最后一个数为MAX
  如果 第一个数+3*X<target 则直接跳过   这样以后能够打败93.3%的用户
  author :ztc
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector<vector<int>>ans;
        if(nums.size()<4) return ans;
        
        sort(nums.begin(),nums.end());
        int MAX=nums.back();
   
        for(int i=0;i<nums.size()-3;i++)
        {
            if(i!=0&&nums[i]==nums[i-1]) continue;
            if(nums[i]+3*MAX<target) continue;
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


/*
author: ypz
*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        if(nums.size() < 4) return ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 3; i++) {
            int z = nums[i];
            if(i > 0 && z == nums[i - 1]) continue;
            for(int m = i + 1; m < nums.size() - 2; m++) {
                int a = nums[m];
                if(m > i + 1 && a == nums[m - 1]) continue;
                for(int j = m + 1, k = nums.size() - 1; j < k; ) {
                    int b = nums[j];
                    int c = nums[k];
                    vector<int> element = {z, a, b, c};
                    if(z + a + b + c == target) {
                        ans.push_back(element);
                        while(j < k && b == nums[++j]);
                        while(j < k && c == nums[--k]);
                    }
                    else if(z + a + b + c > target) k--;
                    else j++;
                }
                
            }

        }
        return ans;
    }
};
