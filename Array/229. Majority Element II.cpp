
/*
  
    这种对一个散乱数组找符合条件的元素，第一个想到的思路最好都是先排序，对于一个散乱数组的统计如果不借助O(n)的额外空间是非常难以实现的，这也是典型的
    时间换空间的策略，排序以后直接比较i  i+n/3 是否相同，是的话 i直接跳转到i+n/3+1 这样虽然时间复杂度没变，但是对于大多数情况能够极大缩小运行时间，
    理想情况O(1)



*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        set<int>ans;
        vector<int> ret;
        int count=nums.size()/3;    
        
        for(int i=0;i<nums.size()-count;)
        {
            if(nums[i]==nums[i+count])
            {
                ans.insert(nums[i]);
                i+=count;
            }
            i++;
        }
       ret.assign(ans.begin(),ans.end());
        return ret;
    }
};


/*
      那么在数组中找到所有大于N/k的数怎么办？
      大于N/k的数最多有k-1个，用一个map存着k-1个数
      （答案参考博客）
      
      在map中，新来一个元素如果在map，则++，不在则插入，如果map的大小到了k，那么对map的每一个值都--，如果=0，则从map抛弃
      （那刚加入的不是也被删掉了？）
      感觉这个方法有问题，是不是要跳过刚加入的元素？
      
      大于一半 k=2  大于N/3  k=3
*/


vector<int>  printMaxTwo(const vector<int> &A , const int k)
{
    typedef map<int,int>::value_type Elem;
    const int n = A.size();
    map<int,int> idxs;
    for(int i=0;i<n;++i)
    {
        if(idxs.find(A[i]) != idxs.end())
        {
            ++idxs[A[i]];
        }
        else
        {
            idxs.insert(Elem(A[i],1));
            if(idxs.size() == k)
            {
                //if there is a full level in the box
                for(auto iter = idxs.begin(); iter != idxs.end();)
                {
                    --((*iter).second);
                    if((*iter).second == 0) iter = idxs.erase(iter);
                    else ++iter;
                }
            }       
        }
    }
    //If there exists no element in the final box
    vector<int> ret;
    for(auto a: idxs) a.second = 0;
    for(auto a: A)
    {
        if(idxs.find(a) != idxs.end())
            ++idxs[a];
    }
    for(auto a: idxs)
        if(a.second >= n/k) ret.push_back(a.first);
    return ret;

