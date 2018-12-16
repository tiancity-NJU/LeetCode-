/*
author: ypz
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0;
        int j = 0;
        while(i <= m || j <= n) {
            if(i == m && j == n) return;
            else if(i < m && j == n) i++;
            else if((i == m && j < n) || (nums2[j] <= nums1[i])) {
                nums1.insert(nums1.begin() + i, nums2[j]);
                nums1.erase(nums1.end() - 1);
                i++;
                m++;
                j++;
            }
            else i++;
        }
    }
};
