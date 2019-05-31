/*
author: ypz
*/

class Solution {
public:
    int cal(int n) {
        int ans = 0;
        while(n != 0) {
            int temp = n % 10;
            ans += temp * temp;
            n = n / 10;
        }
        return ans;
    }
    
    bool isHappy(int n) {
        unordered_map<int, int> cap;
        while(true) {
            int temp = cal(n);
            if(temp == 1) return true;
            cap[temp]++;
            if(cap[temp] > 1) return false;
            n = temp;
        }
    }
};
