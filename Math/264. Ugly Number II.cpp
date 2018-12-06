



/*

   没有ugly.empty() 会报错。。。不知道为什么


*/

class Solution {
public:
    

    
    
//     int nthUglyNumber(int n) {
        
//         vector<int>ugly;
//         long long i,j,k,m=INT_MAX;
//         for(i=1;i<m;i*=2)
//             for(j=i;j<m;j*=3)
//                 for(k=j;k<m;k*=5)
//                 {
//                     ugly.push_back(k);
//                 }
        
//         sort(begin(ugly),end(ugly));
//         return ugly[n-1];
//     }
    
    
  
      int nthUglyNumber(int n) {
    static vector<int> ugly;
    long long a, b, c, m = INT_MAX;
    if (ugly.empty()) {
        for (a=1; a<=m; a*=2)
            for (b=a; b<=m; b*=3)
                for (c=b; c<=m; c*=5)
                    ugly.push_back(c);
        sort(begin(ugly), end(ugly));
    }
    return ugly[n-1];
}

};
