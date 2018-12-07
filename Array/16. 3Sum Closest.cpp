

/*
  上题类似，但是不同于上题找到即可退出，这题需要找到最近的，因此需要遍历全体，还是利用 一个 O(n)的遍历搭配 two points的方法，同时需要注意一个临界
  即找到和target一样的就可以退出的，就这一步判断可以从12ms->4ms
  author:ztc
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        
        int i=0;
        if(nums.size()<3) return 0;
        
        sort(nums.begin(),nums.end());
        int close=nums[0]+nums[1]+nums[2];
        for(int i=0;i<nums.size();i++)
        {
            if(i!=0&&nums[i]==nums[i-1]) continue;
            int left=i+1,right=nums.size()-1;
            int goal=target-nums[i];
            while(left<right)
            {
                int tmp=nums[left]+nums[right];
                if(tmp==goal) return target;
                
                close=(abs(goal-tmp)<abs(target-close))?nums[i]+tmp:close;
                if(tmp<goal) left++;
                else right--;
             
               
            }
        }
        
        return close;
        
        
    }
};

/*
author: ypz
*/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        if(nums.size() < 3) return 0;
        int best = INT_MAX;
        int now;
        int ans;
        for(int i = 0; i < nums.size() -2; i++) {
            for(int j = i + 1; j < nums.size() - 1; j++) {
                for(int k = j + 1; k < nums.size(); k++) {
                    int temp = nums[i] + nums[j] + nums[k];
                    if(temp - target > 0) now = temp - target;
                    else now = target - temp;
                    if(now < best) {
                        best = now;
                        ans = temp;
                    }
                }
            }
        }
        return ans;
    }
};
