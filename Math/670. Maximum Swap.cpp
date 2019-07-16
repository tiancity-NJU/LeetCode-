/*
author: ypz
*/


class Solution {
public:
    int maximumSwap(int num) {
        if(num < 10)
            return num;
        string str = to_string(num);
        int max_val = -1; 
        int max_ind = -1;
        int left = -1;
        int right = -1;
        for(int i = str.size() - 1; i >= 0; i--) {
            // 寻找最大值并保存索引
            if(str[i] > max_val) {
                max_val = str[i];
                max_ind = i;
                continue;
            }
            
            //确定交换的索引，且保证如果出现重复最大值，交换最低位的最大值索引
            if(str[i] < max_val) {
                left = i;
                right = max_ind;
            }
        }
        swap(str[left], str[right]);
        return stoi(str);
    }
};
