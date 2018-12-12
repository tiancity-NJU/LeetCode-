class Solution {
public:

    /*
    By backtracking
    注意元素可以重复使用，因此在进入下一次回溯前不要删除当前元素。
    author: ypz
    */
    
    void backTracking(vector<vector<int>>& ans, vector<int>& candidates, vector<int>& cur, int temp, int target) {
        if(temp == target) {
            ans.push_back(cur);
            return;
        }
        else if(temp > target || candidates.size() == 0) return;
        else {
            for(int i = 0; i < candidates.size(); i++) {
                vector<int> list(candidates);
                vector<int> curr(cur);
                int tmp = temp;
                if(i != 0) list.erase(list.begin(), list.begin() + i);
                curr.push_back(list[0]);
                tmp += list[0];
                backTracking(ans, list, curr, tmp, target);
            }
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        if(candidates.size() == 0) return ans;
        vector<int> cur;
        int temp = 0;
        backTracking(ans, candidates, cur, temp, target);
        return ans;
    }
};



/*
    另外一种写法，相比于上述方法具有更快的速度，思想是先将candidates排序，当去到的数超过target时，后面的都不需要递归了，缩短了时间
    另外可以增加一个约束，即down，每次只能取down及其以上的数，避免了进入  3,2,2 2,3,2 这样的重复状态。超过了99.87%的答案
*/

class Solution {
public:
    
    
    void dfs(vector<int>&arr,int remain,vector<int>&one,vector<vector<int>>&ans,int down)
    {
        if(remain<0) return;
        if(remain==0)
        {
            ans.push_back(one);
            return;
        }
        
        for(auto c:arr)
        {
            if(c<down) continue;
            if(remain-c<0) break;
            one.push_back(c);
            dfs(arr,remain-c,one,ans,c);
            one.pop_back();
        }
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>one;
        int down=candidates[0];
        dfs(candidates,target,one,ans,down);
       
        return ans;
    }
};
