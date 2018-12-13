/*
author: ypz
*/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if(digits[digits.size() - 1] != 9) digits[digits.size() - 1] += 1;
        else {
            for(int i = digits.size() - 1; i >= 0; i--) {
                digits[i] = 0;
                if(i != 0 && digits[i - 1] != 9) {
                    digits[i - 1] += 1;
                    break;
                }
                else {
                    if(i == 0) digits.insert(digits.begin(), 1);
                }
            }
        }
        return digits;
    }
};
