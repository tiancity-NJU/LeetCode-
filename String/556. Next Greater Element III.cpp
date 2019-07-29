/*
author: ypz
思路同之前一道找下一个排列的问题。
*/

class Solution {
public:
    int nextGreaterElement(int n) {
        string str = to_string(n);
        int i = str.size() - 1;
        int flag = 0;
        for(i; i > 0; i--) {
            if(str[i - 1] < str[i]) {
                flag = 1;
                break;
            }
        }
        
        if(flag == 0)
            return -1;
        i--;
        int j = str.size() - 1;
        for(j; j > i; j--) {
            if(str[j] > str[i])
                break;
        }
        swap(str[i], str[j]);
        string left = str.substr(0, i + 1);
        string right = str.substr(i + 1, str.size() - i - 1);
        reverse(right.begin(), right.end());
        string sum = left + right;
        return stoll(sum) > INT_MAX ? -1 : stoll(sum);
    }
};
