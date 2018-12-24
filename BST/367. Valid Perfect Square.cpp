
/*
  找完全平方数，利用线性遍历肯定很慢，因此利用二分查找，但是利用了一些trick，最重要的问题就是可能mid*mid大大越界，甚至转回来一圈，因此
  设定一个upper，在这里是46340，大于这个数的平方肯定越界
*/

class Solution {
public:
    bool isPerfectSquare(int num) {        
        int left=1,right=num;

        while(left<=right)
        {
            int mid=left+(right-left)/2;
            if(mid>46340){right=mid-1;continue;}
            int tmp=mid*mid;
            
            if(tmp==num) return true;
            if(tmp<num) left=mid+1;
            else right=mid-1;
        }
        
        
        return false;
    }
};


/*
  还有一种就是数学方法，没什么意思的题目
*/

class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num == 1) return num;
        long s = 1;
        int add = 1;
        for (int i = 0; ; ++ i) {
            add += 2;
            s += add;
            if ( s == num ) {
                return true;
            }
            else if (s > num) {
                return false;
            }
        }
        return false;

    }
};
