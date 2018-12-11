
/*
  从右往左覆盖，比较简单
*/


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int pos=nums1.size()-1;
        m--;
        n--;
        while(m>=0&&n>=0)
        {
            if(nums1[m]>=nums2[n]) {nums1[pos--]=nums1[m];m--;}
            else {nums1[pos--]=nums2[n];n--;}
            
        }
        if(n<0) return;
        for(;n>=0;n--)
            nums1[n]=nums2[n];
        
        return; 
    }
};
