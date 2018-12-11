

/*
   该题传统意义上可以用过map的形式解决，但是仔细观察后发现，只有26个小写字母，这样完全可以用一个数字表示一个字符串，最后比较
   a|b==a+b 即可判断是否包含公共字母。
*/



class Solution {
public:
    int maxProduct(vector<string>& words) {
        
        vector<int>hash(words.size(),0);
        
        for(int i=0;i<words.size();i++)
        {
            int tmp=0;
            for(auto c:words[i])
                tmp|=1<<(c-'a');
            hash[i]=tmp;
           
        }    
        int MAX=0;
        for(int i=0;i<words.size();i++)
            for(int j=i+1;j<words.size();j++)
            {
                if((hash[i]|hash[j])==(hash[i]+hash[j]))
                {
                   
                    MAX=max(MAX,(int)words[i].size()*(int)words[j].size());
                }
            }
        return MAX;
    }
    
};
