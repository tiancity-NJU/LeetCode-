
/*

   比较简单的一道题，但是里面涉及了最基本最核心的二分法的框架，对于寻找一个特定的数，left指向第一个元素，right指向最后一个元素
   
   然后while判定时需要添加 = 
   while(left<=right)
   在后面缩小范围的时候     right=mid-1    left=mid+1;
   当right不使用   mid-1的时候  一般情况不会错，但是当数组没有包含想要元素的时候，就会无限循环
   
   如果只是找一个范围   while循环里面不添加等号  那么right更新可以==mid
   


*/





// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        
        int left=0,right=n;
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            int back=guess(mid);
            if(back==0) return mid;
            if(back==-1) right=mid-1;   
            if(back==1) left=mid+1;
        }
        return 0;
        
    }
};



/*
  while里面不包含等号的情况，需要对最后left=right多进行一次判断

*/



// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        
        int left=0,right=n;
        while(left<right)
        {
            int mid=left+(right-left)/2;
            int back=guess(mid);
            if(back==0) return mid;
            if(back==-1) right=mid;  
            if(back==1) left=mid+1;
        }
        if(left==right&&guess(left)==0) return left;
        return 0;
        
    }
};

