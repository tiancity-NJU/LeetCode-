/*
author：ypz
方法一： 暴力求解
*/

class Solution {
public:
    int findElement(vector<int>& nums, int element) {
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == element)
                return i;
        }
        return -1;
    }
    
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        for(int i = 0; i < nums1.size(); i++) {
            int index = findElement(nums2, nums1[i]);
            if(index == -1)
                ans.push_back(index);
            else {
                int j = index + 1;
                for(j; j < nums2.size(); j++) { 
                    if(nums2[j] > nums1[i]) {
                        ans.push_back(nums2[j]);
                        break;
                    }
                }
                if(j == nums2.size())
                    ans.push_back(-1);
            }
        }
        return ans;
    }
};
