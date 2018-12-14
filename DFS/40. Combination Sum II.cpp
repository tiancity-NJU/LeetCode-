
/*
  该题的难点在于如何保证一个元素只用一次的同时还能够出现重复元素，比如  [1,7,1,2,5,6] target=8 答案是 [[1,7],[1,2,5],[1,1,6]] 如果像
  上一题那样简单制定一个取值下界，那么1,1,6将无法得到，如果要把下界包括自己(即后续只能取自身或者自身以上) 那么就会出现两个 1,2,5，虽然可以利用set
  简单的避免这个问题，但其实只要再增加一些小的约束，不仅能够减少回溯的次数，还能够利用数组直接实现
  
  首先我们要对candidates排序，接着从floorID+1处开始循环(保证不会取到自身或者前面的元素)，这个时候就有两个区别:
    1.如果存在重复元素，在同一个remain下，只能取一次
    2.如果存在重复元素，在不用的remain下，即不同层次的dfs下能够重复取
    这样针对 1,1,6这个情况， 第一个1的remain是8，第二个1的remain是7，所以可以取，但是针对1(左),2,5 和1(右),2,5的情况，由于1,1都处于
    target为8的层次，那么只需要取一次即可。

*/

class Solution { 
private:
    void dfs(vector<int>&candidates,int remain,int floorID,vector<int>&one,vector<vector<int>>&ans)
    {
        if(remain<0) return;
        if(remain==0){ans.push_back(one);return;}
        
        for(int i=floorID+1;i<candidates.size();i++)
        {
            if(i!=floorID+1&&candidates[i]==candidates[i-1]) continue;
            one.push_back(candidates[i]);
            dfs(candidates,remain-candidates[i],i,one,ans);
            one.pop_back();
        }
    }
    
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        sort(candidates.begin(),candidates.end());
        vector<int>one;
        vector<vector<int>>ans;
        dfs(candidates,target,-1,one,ans);
        return ans;      
    }
};



/*
By backtracking
首先将candidates按从小到大排序，与39题不同点在于由于每个元素只能使用一次，因此进入下一次回溯前需删除当前元素。
注意易错点为可能会出现重复结果，需要在每次for循环时，避免相同元素作为起始点。
author: ypz
*/

class Solution {
public:
    
    void backTracking(vector<vector<int>>& ans, vector<int>& candidates, vector<int>& cur, int temp, int target) {
        if(temp == target) {
            ans.push_back(cur);
            return;
        }
        else if(temp > target || candidates.size() == 0) return;
        else {
            for(int i = 0; i < candidates.size(); i++) {
                if(i != 0 && candidates[i] == candidates[i - 1]) continue;
                vector<int> list(candidates);
                vector<int> curr(cur);
                int tmp = temp;
                if(i != 0) list.erase(list.begin(), list.begin() + i);
                curr.push_back(list[0]);
                tmp += list[0];
                list.erase(list.begin());
                backTracking(ans, list, curr, tmp, target);
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        if(candidates.size() == 0) return ans;
        vector<int> cur;
        int temp = 0;
        sort(candidates.begin(), candidates.end());
        backTracking(ans, candidates, cur, temp, target);
        return ans;
    }
};
