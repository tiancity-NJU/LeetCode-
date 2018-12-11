
/*
  一开始没注意不让转化数字，因此直接写一个atoi就行
  但是如果直接使用字符，会变得比较麻烦，利用一个二重循环，一位一位的乘，保留进位。该方法是参考别人的解法。

*/


class Solution {
public:
  
    string multiply(string num1, string num2) {
    
        string answer(num1.length() + num2.length() + 1, '0');
        int ans_pos = answer.length() -1;
        int mult_pos = ans_pos;

        for (int i = num1.length() - 1; i >= 0; i--) {
            for (int j = num2.length() - 1; j >= 0; j--) {
                int result = ((num1[i] - '0')*(num2[j] - '0')) + (answer[ans_pos] - '0');
                answer[ans_pos] = (result % 10) + '0';
                answer[ans_pos-1] = ((result / 10) + (answer[ans_pos - 1] - '0')) + '0';
                ans_pos--;
            }
                mult_pos--;
                ans_pos = mult_pos;
            }

        while (answer[0] == '0') {
            answer.erase(answer.begin());
        }
        return answer.length() > 0 ? answer : "0";
    } 
};
