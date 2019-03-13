

/*
  
  除了找第k大值这种比较直观的问题可以采用堆或者partition以外，这种随着数组长度而指数递增的状态值，要找第k大最常用的就是值域二分，统计mid左右的数量
  不断缩小范围
  
  该题的难点在于二分的边界条件，假设ans=l=r，那么统计出来的cnt<k的，此时l=mid+1，那么正确答案应该是没有改变的r
*/

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        
        if(nums.size()==0 || nums.size()*(nums.size()-1)<k) return 0;
        
        sort(nums.begin(),nums.end());
        int Min=INT_MAX,Max=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            Min=min(Min,nums[i+1]-nums[i]);
        }
        Max=nums.back()-nums[0];
        int l=Min,r=Max;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            int j=0;
            int cnt=0;
            for(int i=0;i<nums.size();i++)
            {
                while(j<nums.size()&&nums[j]-nums[i]<mid) j++;
                cnt+=j-i-1;
            }
            cnt>=k?r=mid-1:l=mid+1;
        }
        return r;
    }
        
};
