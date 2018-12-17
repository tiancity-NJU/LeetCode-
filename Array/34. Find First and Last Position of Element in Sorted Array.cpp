class Solution {
public:
    
    /*
    author:ypz
    */
    
    vector<int> searchRange(vector<int>& nums, int target) {
        // 首先计算最左的索引值
        int left = 0, right = nums.size();
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] >= target) right = mid;
            else left = mid + 1;
        }
        if(left == nums.size() || nums[left] != target) return {-1, -1};
        // 其次计算最右的索引值
        int start = left;
        right = nums.size();
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] > target) right = mid;
            else left = mid + 1;
        }
        int end = left - 1; 
        return {start, end};
    }
};

/*
    还有一种思路就是利用二分法靠近趋势的修改，比如
    mid=left+(right-left)/2  mid是更加靠近left的    如果 mid=left+(right-left+1)/2 则mid是更加靠近right的

*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        
        int left=0,right=nums.size()-1;
        vector<int>ans(2,-1);
        
        if(nums.size()==0)
        {
            return ans;
        }
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            if(nums[mid]>=target) right=mid-1;
            else left=mid+1;
        }
        if(left>=nums.size()||nums[left]!=target) {ans[0]=-1;ans[1]=-1;return ans;}
        ans[0]=left;
        
        left=0;right=nums.size()-1;
        while(left<=right)
        {
            int mid=left+(right-left+1)/2;
            if(nums[mid]<=target) left=mid+1;
            else right=mid-1;
        }
        if(right<0||nums[right]!=target) {ans[0]=-1;ans[1]=-1;return ans;}
        ans[1]=right;
        return ans;
    }
};
