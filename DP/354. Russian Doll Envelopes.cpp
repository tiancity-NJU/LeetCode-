
/*
  总的来说，是一个比较标准的DP问题，需要先进行排序预处理，保证升序，写的过程过慢，需要加快速度
   这是一个O(n) 空间  O(n2) 时间的DP问题，灵活应用

*/



class Solution {
private:
    static bool cmp(const pair<int,int>&a,const pair<int,int>&b)
    {
        if(a.first!=b.first) return a.first<b.first;
        return a.second<b.second;
    }
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        
        if(envelopes.size()==0) return 0;
        sort(envelopes.begin(),envelopes.end());
        
        vector<int>DP(envelopes.size(),0);
        int count=0;
        
        
        for(int i=0;i<envelopes.size();i++)
        {
            DP[i]=1;
            for(int j=0;j<i;j++)
            {
                if(envelopes[j].first<envelopes[i].first&&envelopes[j].second<envelopes[i].second)
                    DP[i]=max(DP[i],DP[j]+1);
            }
        }
        
        for(auto c:DP) count=max(count,c);
        
        return count;
         
    }
};
