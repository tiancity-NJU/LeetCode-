/*

最常用的问题是对一个有序数组或者列表的查询，利用递归的方法,这样可以保证运行时间在O(lgn)：

*/
class Solution {
public:
    
    void BST(vector<int>&nums,int s,int e,int target,int& res)
    {
        if(s>=e) return;
        int mid=(e+s)/2;
        if(nums[mid]==target) {res=mid;return;}
        if(nums[mid]>target)
            BST(nums,s,mid,target,res);
        else BST(nums,mid+1,e,target,res);
        
        
    }
    
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        
        int remain;
        int find=-1;
        for(int i=0;i<numbers.size();i++)
        {
            remain=target-numbers[i];
            BST(numbers,i,numbers.size(),remain,find);
            if(find!=-1){ans.push_back(i+1);ans.push_back(find+1);break;}
        }
        return ans;
    }
};
