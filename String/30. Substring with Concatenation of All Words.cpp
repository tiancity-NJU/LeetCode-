
/*
  比较直观的，就是对每一个位置开始的字符串进行检查，由于长度相等，在第二层循环的时候可以简化一部分的计算，但是还是会出现大量重复计算
  （或许可以利用KMP等方法的思路进行优化）

*/


class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if(words.size()==0) return ans;
        for(int i=1;i<words.size();i++)
        {
            if(words[i].size()!=words[0].size()) return ans;
        }
        
        unordered_map<string,int>alpha;
        for(auto c:words)
        {
            if(alpha.find(c)==alpha.end()) alpha[c]=1;
            else alpha[c]++;
        }
        
        
        int len=words[0].size(),num=words.size(),total=s.size();
        for(int i=0;i<total-num*len+1;i++)
        {
            int j=0;
            unordered_map<string,int>seen(alpha);
            for(;j<num*len;j+=len)
            {
                if(seen.find(s.substr(i+j,len))==seen.end()) break;
                if(--seen[s.substr(i+j,len)]==-1) break;
            }
            if(j==num*len) ans.push_back(i);
        }
        return ans;
    }
};
