
/*
  只要前两个数字确定了以后，后来的数字就是确定的，因此只需要在主函数里面遍历，接着dfs即可
  主要是匹配的判断和下一层的进入，另外0只能单独出现，利用字符串的组合进行匹配，这题花了较长时间，但是并不是很难
*/


class Solution {
    
private:
    
    int64_t atoi(string s)
    {
        int64_t sum=0;
        for(auto c:s)
        {
            sum*=10;
            sum+=c-'0';
        }
        return sum;
    }
    
    bool illegal(const string& s)
    {
        if(s=="") return true;
        if(s=="0") return false;
        if(s.size()>1&&s[0]=='0') return true;
        return false;
    }
    
    
    bool dfs(const string& a,const string& b,const string& remain)
    {
        
        if(illegal(a)||illegal(b)) return false;
      
        int64_t c=atoi(a)+atoi(b);
        string tmp=a+b+to_string(c);
        if(tmp==remain) return true;
        if(tmp.size()>=remain.size()) return false;
        
        if(remain.substr(0,tmp.size())==tmp)
        {
            return dfs(b,to_string(c),remain.substr((int)a.size()));
        }
        
        return false;
           
    }
    
public:
    bool isAdditiveNumber(string num) {
        
        if(num.size()<3) return false;
        
        for(int i=1;i<num.size()-1;i++)
        {
            string a=num.substr(0,i);
            if(illegal(a)) continue;
            for(int j=i;j<num.size()-1;j++)
            {
                string b=num.substr(i,j-i+1);
                if(illegal(b)) continue;
                if(dfs(a,b,num)) return true;
            }
        }
        
        return false;
        
        
    }
};
