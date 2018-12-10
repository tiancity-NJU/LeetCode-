
/*

  能想到的第一个策略肯定是0(n2)的循环，但是这样肯定是非常慢的，因此考虑利用hash map来构造，k-v对是   与数值k相加能成为target的数的索引

*/


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>answer;
        unordered_map<int,int>m;
        int tmp;
        for(int i=0;i<nums.size();i++)
        {
            if(m.find(nums[i])!=m.end())
            {
                answer.push_back(m[nums[i]]);
                answer.push_back(i);
            }
            else
            {
                tmp=target-nums[i];
                m[tmp]=i;
            }
        }
        return answer;
        
    }
};
