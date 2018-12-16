

/*
    虽然AC，但是解法过于牵强，还进行了n<4 和 n>4 的分类，这在DP问题中是不希望看到的
    一个数拆成若干个数的和必然是可能总结为两个数的和  比如  10=3+3+4 最大，可以总结为 DP[6]*DP[4],所以我们可以很容易的得到状态转移方程
    另外DP[6]*DP[4]等价于 DP[4]*DP[6] 因此我们只需要对j从i/2开始循环即可。
*/


class Solution {
public:
    int integerBreak(int n) {
        
        vector<int>DP(n+1,0);
        
        if(n<4) return n-1;
        for(int i=1;i<=n;i++) DP[i]=i;
        
        for(int i=1;i<=n;i++)
        {
            for(int j=i/2;j<i;j++)
            {
                DP[i]=max(DP[i],DP[j]*DP[i-j]);
            }
        }
        
        return DP[n];
        
        
    }
};


/*
    后来网上存在一种针对该问题比较特殊的一种解法，往后写一些答案就可以发现，几乎所有的答案都可以拆成 2 3 4的形式，又 4=2*2 就全部变成
    2 3的形式，又3的更大，则尽可能拆3，不够的拆2

*/

class Solution {
public:
    int integerBreak(int n) {
        int result = 1;

        if (n <= 4) 
            return n == 4? 4: n-1;

        while (n > 4) {
            result *= 3;
            n -= 3;
        }

        return result * n;
    }
};
