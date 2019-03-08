
/*

    这一题一直有一个疑问，定义一个static 的cmp函数，cmp中调用我们定义的prior数组，而这个数组需要根据S的出现顺序进行调整，
    这样无论prior加不加static都无法运行，只能通过这种在sort函数里面定义cmp的方式进行。。。具体形式如下：
    
    
    vector<int>prior;
    static cmp(....)
    {
    return prior[a]<prior[b];
    }
    
    void run(S,T)
    {
       init prior;
       sort(T.begin(),T.end(),cmp);
    }
    
    报错
       

*/


class Solution {
      
public:
    string customSortString(string S, string T) {
        
        int p=1;
        vector<int>dir(26,27);
        for(auto c:S)
        {
            if(dir[c-'a']==27) dir[c-'a']=p++;
        }
        
        if(T.size()==0) return T;
        sort(T.begin(),T.end(),[&](char a, char b) { return dir[a-'a'] < dir[b-'a'];});
        return T;
        
    }
};
