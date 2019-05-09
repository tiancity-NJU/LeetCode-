const int d = 'a' - 'A';
    
class Solution {
public:
    bool judgeAZ(char x) {
        if(x >= 'A' && x <= 'Z') return true;
        else return false;
    }
    
    bool judgeaz(char x) {
        if(x >= 'a' && x <= 'z') return true;
        else return false;
    }
    
    bool judge09(char x) {
        if(x >= '0' && x <= '9') return true;
        else return false;
    }
    
    char az2AZ(char x) {
        if(x >= 'a' && x <= 'z') return x - d;
        else return x;
    }
    
    bool isPalindrome(string s) {
        if(s.size() == 0) return true;
        int left = 0, right = s.size() - 1;
        while(left <= s.size() - 1 && !(judgeAZ(s[left]) || judgeaz(s[left]) || judge09(s[left])))
            left++;
        while(right >= 0 && !(judgeAZ(s[right]) || judgeaz(s[right]) || judge09(s[right])))
            right--;
        while(left <= right) {
            char a = az2AZ(s[left]);
            char b = az2AZ(s[right]);
            if(a != b) return false;
            left++;
            right--;
            while(left <= s.size() - 1 && !(judgeAZ(s[left]) || judgeaz(s[left]) || judge09(s[left])))
                left++;
            while(right >= 0 && !(judgeAZ(s[right]) || judgeaz(s[right]) || judge09(s[right])))
                right--;
        }
        return true;
    }
};
