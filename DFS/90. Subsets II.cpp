/*
思路同第78题，注意将nums排序后，每次回溯避免起始元素相同即可。
author: ypz
*/

class Solution {
public:
    void backTracking(vector<vector<int>> &ans, vector<int> &curr, vector<int> &nums, int k) {
        if(curr.size() == k) ans.push_back(curr);
        else {
            if(nums.size() == 0) return;
            for(int i = 0; i < nums.size(); i++) {
                if(i != 0 && nums[i] == nums[i - 1]) continue;
                vector<int> curr_temp(curr);
                vector<int> nums_temp(nums);
                curr_temp.push_back(nums[i]);
                nums_temp.erase(nums_temp.begin(), nums_temp.begin() + i + 1);
                backTracking(ans, curr_temp, nums_temp, k);
            }
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        sort(nums.begin(), nums.end());
        for(int i = 0; i <= nums.size(); i++) backTracking(ans, curr, nums, i);
        return ans;
    }
};

/*
  和上面方法差不多，对于重复元素，一定要区分： 答案里面存在重复元素 比如 [1,2,2]  但是不能存在 [1,2,5] [1,2,5] 因此在每一层选取的时候
  不能选同一个数，不同层，可以选不同的数
  核心就是    sort       if(i!=s&&nums[i]==nums[i-1]) continue;
*/

class Solution {
public:
    
    void comb(vector<int>&nums,int s,vector<vector<int>>&ans,vector<int>&tmp)
    {
        ans.push_back(tmp);
        
        for(int i=s;i<nums.size();i++)
        {
            if(i!=s&&nums[i]==nums[i-1]) continue;
            tmp.push_back(nums[i]);
            comb(nums,i+1,ans,tmp);
            tmp.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        vector<int>tmp;
        comb(nums,0,ans,tmp);
        
        return ans;
    }
};
