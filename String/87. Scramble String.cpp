
/*
  利用DFS遍历这个情况，直到直到一个结果，否则退出，注意左右两部分的选取要保证等长
  
*/



class Solution {
public:
    
    
    bool isScramble(string s1, string s2) {
        
        map<char,int>count;
        for(int i=0;i<26;i++)
            count[i]=0;
        
        if(s1.size()!=s2.size()) return false;
        
        if(s1==s2) return true;
        
        for(auto c:s1)
            count[c-'a']++;
        for(auto c:s2)
            count[c-'a']--;
        
        for(auto c:count)
            if(c.second!=0) return false;
        
        
        for(int i=1;i<s1.size();i++)
        {
            if((isScramble(s1.substr(0,i),s2.substr(0,i))&&isScramble(s1.substr(i),s2.substr(i))) || 
               (isScramble(s1.substr(0,i),s2.substr(s2.size()-i))&&isScramble(s1.substr(i),s2.substr(0,s2.size()-i))))
                return true;
        }
        return false;
        
        
    }
};
