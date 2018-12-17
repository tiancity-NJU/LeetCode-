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
        for(int i = 0; i <= nums.size(); i++) backTracking(ans, curr, nums, i);
        return ans;
    }
};


/*
以上方法都是一种DFS的方式，当数据规模很大的时候会出现内存溢出的情况，该问题本质上就是找出所有组合，即对应 00000...000 -> 11111...111 转变过程
中的每一个集合，0代表取，1代表不取
*/

class Solution {
public:
void next(string&s)
{
    int pos=s.size()-1;
    while(s[pos]=='1') pos--;
    s[pos]='1';
    pos++;
    while(pos<s.size()) {s[pos]='0';pos++;}
}

vector<int>parse(vector<int>&nums,string&s)
{
    vector<int>tmp;
    for(int i=0;i<nums.size();i++)
    {
        if(s[i]=='1') tmp.push_back(nums[i]);
    }
    return tmp;
}
    
vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
       
        string s="",end="";
        for(int i=0;i<nums.size();i++) {s+='0';end+='1';}
        
        long long count=1<<(int)nums.size();
        while(s!=end)
        {
            ans.push_back(parse(nums,s));
            next(s);
        }
        ans.push_back(nums);
        return ans;
    }
};
