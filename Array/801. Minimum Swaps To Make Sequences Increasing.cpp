
/*
     dp不难想到，关键在于如何构建dp数组，一开始想着设置[2005][2005]即前一轮A,B结尾数字时的最小交换数，但是这样空间太大，而且容易绕糊涂，
     只需要维护两个dp数组即可，平时的dp问题除了最简单的一维dp外，还需要考虑二维dp或者多组dp

*/


class Solution {
public:

  int minSwap(vector<int>& A, vector<int>& B) {
    const int n = A.size();
        
    vector<int> keep(n, INT_MAX);
    vector<int> swap(n, INT_MAX);
    
    keep[0] = 0;
    swap[0] = 1;
    
    for (int i = 1; i < n; ++i) {
      if (A[i] > A[i - 1] && B[i] > B[i - 1]) {
        keep[i] = keep[i - 1];
        swap[i] = swap[i - 1] + 1;
      }      
      
      if (B[i] > A[i - 1] && A[i] > B[i - 1]) {
        swap[i] = min(swap[i], keep[i - 1] + 1);     
        keep[i] = min(keep[i], swap[i - 1]);
      }      
    } 
    return min(keep.back(), swap.back());

    }
};
