/*
author: ypz
定义一个cmp函数。
*/

class Solution {
public:
    static bool cmp(int a, int b) {
        string x = to_string(a);
        string y = to_string(b);
        return x + y > y + x;
    }
    
    string largestNumber(vector<int>& nums) {
        string ans = "";
        sort(nums.begin(), nums.end(), cmp);
        for(int i = 0; i < nums.size();i++) 
            ans += to_string(nums[i]);
        
        if(ans[0] == '0') 
            return "0";
        else
            return ans;
    }
};
