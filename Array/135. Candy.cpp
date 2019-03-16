
/*
  
   虽然是hard题，但是相对不是太难，我们需要考虑每个人左边和右边的情况，因此一次从左到右的遍历肯定不行，那就左右都找一次，取左右最小值的最大值
   贪心的策略

*/


class Solution {
public:
    int candy(vector<int>& ratings) {
        
        vector<int>assign(ratings.size(),1);
        for(int i=1;i<ratings.size();i++)
        {
            if(ratings[i]>ratings[i-1])
                assign[i]=max(assign[i],assign[i-1]+1);
        }
        
        
        for(int i=ratings.size()-2;i>=0;i--)
        {
            if(ratings[i]>ratings[i+1])
                assign[i]=max(assign[i],assign[i+1]+1);
        }
        int sum=0;
        for(auto c:assign)
            sum+=c;
        return sum;
    }
};
