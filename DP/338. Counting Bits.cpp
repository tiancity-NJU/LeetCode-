/*
  
      DP不能只局限于前后一位的关系，例如  10111 只比 1011多一个1  10110和 1011一样多的0，这样姐很好确定了

*/




class Solution {
public:
    vector<int> countBits(int num) {
        
        vector<int>DP(num+1,0);
        
        for(int i=1;i<=num;i++)
        {
            DP[i]=DP[i>>1]+i%2;
        }
        
        return DP;  
    }
};
