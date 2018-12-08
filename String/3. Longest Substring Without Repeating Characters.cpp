
/*

  第一种是相对暴力的方法，维护一个“纯净”的字符串result，每次都在result里面查找新到来字符的位置，如果找不到，就直接加进去，如果找到了，更新
  最长长度，然后该位置（包括自己）之前的所有元素，最后别忘乐再比较一次用来处理尾端的情况。


*/


class Solution {
public:
    
int findPos(string s, char c) {
	int pos = -1;
	for (int i = 0; i<s.length(); i++)
	{
		if (s[i] == c)
			pos = i;
	}
	return pos;
}

int lengthOfLongestSubstring(string s) {
	string result;
	int len = 0;
	int pos;
	for (int i = 0; i < s.length(); i++)
	{
		pos = findPos(result, s[i]);
		result += s[i];
		if (pos != -1) {
			if (len < result.length() - 1)
				len = result.length() - 1;

			result = result.erase(0, pos + 1);

		}
	}

	return result.length() > len ? result.length() : len;

}
};





/*

  上面的方法相对比较野蛮，再次看到这个问题想到利用hash表也可以做，可以维护一个字符到出现该字符最后位置索引的一个映射
  如果当前索引减去当前长度 i-len> hs[s[i]] 或者hs[s[i]]为空，都说明在当前考虑的子串里，s[i]第一次出现，更新hs[s[i]]
  否则更新len和hs[s[i]]，具体方法如下

*/



class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>hs;
        int maxLen=0;
        int len=0;
        int i=0;
        while(i<s.size())
        {
            if(hs.find(s[i])==hs.end()||i-hs[s[i]]>len){hs[s[i]]=i; i++;len++;continue;}
            maxLen=max(maxLen,len);
            len=i-hs[s[i]];
            hs[s[i]]=i;
            i++;
        }
        return max(maxLen,len);
    }
};
