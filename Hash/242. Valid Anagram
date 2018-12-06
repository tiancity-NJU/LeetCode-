/*

  题目意思没太明白。。一开始想复杂了，就是统计字符数目可一致


*/



class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        vector<int>m(26,0);
        
        for (int i = 0; i < s.size(); i++) m[s[i] - 'a']++;
        
        for (int i = 0; i < t.size(); i++) {
            if (--m[t[i] - 'a'] < 0) return false;
        }
        return true;
    }
};
