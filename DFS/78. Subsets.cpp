/*
  典型的DFS问题，这种问题和求所有排列组合的问题一样，较为通用的框架为
  DFS(data, sIndex,eIndex,int goalCondition,&tmpResult,&Result)
  {
            if(sIndex>eIndex) return;
            if(goalCondition) Result_push_back(tmpResult); return;
            
            update(tmpResult)
            
            DFS(data,sIndex+1,eIndex,goalCondition,tmpResult,Result)
  }
  另外该类问题还可以通过 bitmap解决
  author: ztc
*/

class Solution {
public:
    
    void comb(vector<int>list,int s, int e,int  len,vector<vector<int>>&result,vector<int>&condition)
{
	int i;

	if (s > e)
		return;

	if (condition.size() == len)
	{
		result.push_back(condition);
		return;
	}

	condition.push_back(list[s]);
	comb(list,s + 1, e, len,result,condition);
	condition.pop_back();
	comb(list,s + 1, e, len,result,condition);
}

vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        for(int i=0;i<=nums.size();i++)
        {
            vector<vector<int>> tmp;
            vector<int>condition;
            comb(nums,0,(int)nums.size(),i,tmp,condition);
            ans.insert(ans.end(),tmp.begin(),tmp.end());
        }
        return ans;
    }
};

/*
    利用bitMap解决,但是这样只能解决特定大小内的数组长度

*/




/*
By backtracking.
author: ypz
*/

class Solution {
public:
    
    void backTracking(vector<vector<int>> &ans, vector<int> &curr, vector<int> &nums, int k) {
        if(curr.size() == k) ans.push_back(curr);
        else {
            if(nums.size() == 0) return;
            for(int i = 0; i < nums.size(); i++) {
                vector<int> curr_temp(curr);
                vector<int> nums_temp(nums);
                curr_temp.push_back(nums[i]);
                nums_temp.erase(nums_temp.begin(), nums_temp.begin() + i + 1);
                backTracking(ans, curr_temp, nums_temp, k);
            }

        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        for(int i = 0; i <= nums.size(); i++) {
            vector<int> curr_temp_temp(curr);
            vector<int> nums_temp_temp(nums);
            backTracking(ans, curr_temp_temp, nums_temp_temp, i);
        }
        return ans;
    }
};
