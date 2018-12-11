
/*
  比较简单的一题，没什么难度，但是需要注意pattern和str要一一对应，不能只用一个map，否则会出现  a->dog b->dog 的情况，需要利用
  两个map互相表示，很多字符串的题目都可以转换成hash的形式 

*/




class Solution {
public:
    bool wordPattern(string pattern, string str) {
        
        unordered_map<char,string>p2s;
        unordered_map<string,char>s2p;
        
        vector<string>word;
        string tmp="";
        for(int i=0;i<str.size();i++)
        {
            if(str[i]==' ') {if(tmp!="") word.push_back(tmp);tmp="";continue;}
            tmp+=str[i];
        }
        if(tmp!="") word.push_back(tmp);
        
        if(pattern.size()!=word.size()) return false;
        
        for(int i=0;i<pattern.size();i++)
        {
            if(p2s.find(pattern[i])==p2s.end()&&s2p.find(word[i])==s2p.end()) 
            {
                p2s[pattern[i]]=word[i];   
                s2p[word[i]]=pattern[i];
            }
            if(p2s[pattern[i]]!=word[i]||s2p[word[i]]!=pattern[i]) return false;
        }
        return true;
        
    }
};
