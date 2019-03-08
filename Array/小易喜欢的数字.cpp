

/*


小易非常喜欢拥有以下性质的数列:
1、数列的长度为n
2、数列中的每个数都在1到k之间(包括1和k)
3、对于位置相邻的两个数A和B(A在B前),都满足(A <= B)或(A mod B != 0)(满足其一即可)
例如,当n = 4, k = 7
那么{1,7,7,2},它的长度是4,所有数字也在1到7范围内,并且满足第三条性质,所以小易是喜欢这个数列的
但是小易不喜欢{4,4,4,2}这个数列。小易给出n和k,希望你能帮他求出有多少个是他会喜欢的数列。



      最近经常碰到这种题型，题目要求求一个特别庞大的情况数，DP，一般是二维或者三维，关键在于需要保存多少信息
      对于本题，相邻两种情况需要考虑的有当前长度，以及前一个状态的最后一位数字是多少，所以需要设置二维数组
      [n][k] 表示长度为n，且以k结尾的满足条件的序列有多少个
      这种问题的最难点在于初始化，其次才是状态转移方程
      状态转移方程是对于长度n，总数肯定是继承n-1的所有情况，然后减去  n-1 中不符合结尾条件的即可
*/


#include<iostream>
#include<vector>
using namespace std;


void Run(int n,int k)
{
    int total=0;
    int M=1000000007;
    vector<vector<int>>dp(11,vector<int>(100005,0));
    for(int i=1;i<=k;i++) dp[1][i]=1;
    
    for(int i=2;i<=n;i++)
    {
        int64_t sum=0;
        for(int j=1;j<=k;j++) {sum+=dp[i-1][j]; sum=sum%M;}
        for(int j=1;j<=k;j++)
        {
            dp[i][j]=sum;
            for(int p=2*j;p<=k;p+=j) {dp[i][j]-=dp[i-1][p],dp[i][j]=dp[i][j]%M;}
        }
    }
    int64_t res=0;
    for(int i=1;i<=k;i++) {res+=dp[n][i];res=res%M;}
    cout<<res<<endl;
}



int main()
{
    int n,k;
    cin>>n>>k;
    Run(n,k);
    return 0;
}
