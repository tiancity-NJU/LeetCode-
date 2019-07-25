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

/*
author：ypz
方法二：采用栈和哈希表
借助一个栈和一个哈希表，当右值小于左值时入栈，否则出栈，哈希表用来存储该值右边第一个大值。
*/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        unordered_map<int, int> m;
        vector<int> ans;
        for(int i = 0; i < nums2.size(); i++) {
            while(s.size() && s.top() < nums2[i]) {
                m[s.top()] = nums2[i];
                s.pop();
            }
            s.push(nums2[i]);
        }
        for(int i = 0; i < nums1.size(); i++) {
            if(m.count(nums1[i]) != 0)
                ans.push_back(m[nums1[i]]);
            else
                ans.push_back(-1);
        }
        return ans;
    }
};
