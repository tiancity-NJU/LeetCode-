



/*
  一般这种找几个前K个最值的问题都可以转化为堆问题，堆最大的麻烦就是自定义比较函数，参考了网上的priority_queue 的代码
*/


class Solution {
public:
   
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        using p = pair<int, int>;
        auto cmp = [](const auto& p1, const auto& p2)   // 最大堆
        { 
            return p1.first + p1.second > p2.first + p2.second;
        };
        
        priority_queue<p, vector<p>, function<bool(p, p)>> pq(cmp);
        
        int l1 = min(k, (int)nums1.size()), l2 = min(k, static_cast<int>(nums2.size()));
        
        for (int i = 0; i < l1; ++i)
        {
            for (int j = 0; j < l2; ++j)
            {
                int n1 = nums1[i], n2 = nums2[j];  
                pq.push(make_pair(n1, n2));
            }
        }
     
        std::vector<pair<int, int>> ret;
        while (!pq.empty()&&k--)
        {
            ret.emplace_back(pq.top());
            pq.pop();
        }
        return ret;
    }
    
};

/*

  可以优化的方法就是建立最大堆，比最大堆打就删除堆顶，永远保证堆里只有K个元素
*/

class Solution {
public:
   
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        using p = std::pair<int, int>;
        auto cmp = [](const auto& p1, const auto& p2)   // 最大堆
        { 
            return p1.first + p1.second < p2.first + p2.second;
        };
        
        std::priority_queue<p, std::vector<p>, std::function<bool(p, p)>> pq(cmp);
        
        int l1 = std::min(k, (int)nums1.size()), l2 = std::min(k, static_cast<int>(nums2.size()));
        
        for (int i = 0; i < l1; ++i)
        {
            for (int j = 0; j < l2; ++j)
            {
                int n1 = nums1[i], n2 = nums2[j];
                if (pq.size() < k)
                {
                    pq.push(std::make_pair(n1, n2));
                }
                else if (n1 + n2 < pq.top().first + pq.top().second)
                {
                    pq.pop();
                    pq.push(std::make_pair(n1, n2));
                }
            }
        }
     
        std::vector<std::pair<int, int>> ret;
        while (!pq.empty())
        {
            ret.emplace_back(pq.top());
            pq.pop();
        }
        return ret;
    }
    
};
