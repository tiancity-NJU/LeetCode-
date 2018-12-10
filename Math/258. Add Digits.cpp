/*
  无聊的题目
*/
class Solution {
public:
    int addDigits(int num) {
        
        while(num>9)
        {
            int tmp=0;
            while(num!=0)
            {
                tmp+=num%10;
                num/=10;
            }
            num=tmp;
        }
        
        return num;
    }
};
