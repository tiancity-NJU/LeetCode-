
/*
  
    这种对一个散乱数组找符合条件的元素，第一个想到的思路最好都是先排序，对于一个散乱数组的统计如果不借助O(n)的额外空间是非常难以实现的，这也是典型的
    时间换空间的策略，排序以后直接比较i  i+n/3 是否相同，是的话 i直接跳转到i+n/3+1 这样虽然时间复杂度没变，但是对于大多数情况能够极大缩小运行时间，
    理想情况O(1)



*/




class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        set<int>ans;
        vector<int> ret;
        int count=nums.size()/3;    
        
        for(int i=0;i<nums.size()-count;)
        {
            if(nums[i]==nums[i+count])
            {
                ans.insert(nums[i]);
                i+=count;
            }
            i++;
        }
       ret.assign(ans.begin(),ans.end());
        return ret;
    }
};
