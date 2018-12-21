

/*
  第一种也是最容易想到的就是利用STL的map，然后传递到vecotr中排序，但是中间拷贝过程会花费很长时间，没有找到一种比较清晰的map排序方法
*/


class Solution {
    
private:
    static bool cmp(const pair<int, char> &a,const pair<int, char> &b) {
    return a.second>b.second;
 }
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ret;
        unordered_map<int,int>count;
        for(auto c:nums)
        {
            if(count.find(c)==count.end()) count[c]=1;
            else count[c]++;
        }
        vector<pair<int,int>>ans;
        for(auto c:count)
            ans.push_back(make_pair(c.first,c.second));
     
        sort(ans.begin(),ans.end(),cmp);
        for(int i=0;i<k;i++)
            ret.push_back(ans[i].first);
        
        return ret;
        
    }
};


/*
    还有一种方法就是利用堆，方法差不多，就是用来熟悉一下堆的操作
*/

class Solution {
 private:
    static bool cmp(const pair<int,int>&a,const pair<int,int>&b)
    {
        return a.second<b.second;
    }
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ret;
        unordered_map<int,int>count;
        for(auto c:nums)
        {
            if(count.find(c)==count.end()) count[c]=1;
            else count[c]++;
        }
        vector<pair<int,int>>ans;
        for(auto c:count)
            ans.push_back(make_pair(c.first,c.second));
     
        make_heap(ans.begin(),ans.end(),cmp);
        
      
        for(int i=0;i<k;i++)
        {
            ret.push_back(ans[0].first);
            pop_heap(ans.begin(),ans.end(),cmp);
            ans.pop_back();
        }
        
        return ret;
        
    }
};
