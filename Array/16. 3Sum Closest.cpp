

/*

  上题类似，但是不同于上题找到即可退出，这题需要找到最近的，因此需要遍历全体，还是利用 一个 O(n)的遍历搭配 two points的方法，同时需要注意一个临界
  即找到和target一样的就可以退出的，就这一步判断可以从12ms->4ms


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
