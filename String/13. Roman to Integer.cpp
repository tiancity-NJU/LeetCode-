
/*

  难度不大，但是要写出来比较清晰的比较难，用map会比较好

*/


class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> map = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int ret = 0;
        for (int idx = 0; idx < s.size(); ++idx) {
            if ((idx < s.size()-1) && (map[s[idx]] < map[s[idx+1]])) {
                ret -= map[s[idx]];
            }
            else {
                ret += map[s[idx]];
            }
        }
        return ret;
    }
};


/*
    还有一种更方便的写法
*/



class Solution {
public:
    int romanToInt(string s) {
        
        unordered_map<char,int> M;
        M['I']=1;
        M['V']=5;
        M['X']=10;
        M['L']=50;
        M['C']=100;
        M['D']=500;
        M['M']=1000;
         
        int pre=INT_MAX;
        int now=0;
        int total=0;
        for(int i=0;i<s.size();i++)
        {
            now=M[s[i]];
            if(now>pre) total+=now-2*pre;
            else total+=now;
            pre=now;
        }
        return total;  
    }
};
