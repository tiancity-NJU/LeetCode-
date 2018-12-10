/*
  典型的递归方法，DFS遍历一遍即可，另外利用一个map映射数字和字母
  author: ztc
*/

class Solution {
public:
 	void Count(string digits, map<char, string>L,string s,vector<string>& res)
	{
		if (digits.size() == 0)
		{
			if(s!="")
				res.push_back(s);
			return;

		}
		for (int i = 0; i < L[digits[0]].size(); i++)
		{
			s += L[digits[0]][i];
			Count(digits.substr(1, digits.size()), L, s, res);
			s = s.substr(0, s.size() - 1);
		}
	}

	vector<string> letterCombinations(string digits) {
		map<char, string>L;
		L.insert(pair<char, string>('2', "abc"));
		L.insert(pair<char, string>('3', "def"));
		L.insert(pair<char, string>('4', "ghi"));
		L.insert(pair<char, string>('5', "jkl"));
		L.insert(pair<char, string>('6', "mno"));
		L.insert(pair<char, string>('7', "pqrs"));
		L.insert(pair<char, string>('8', "tuv"));
		L.insert(pair<char, string>('9', "wxyz"));

		vector<string> res;
		string s = "";
		Count(digits, L, s, res);
		return res;
	}
};


/*
By backtracking
author: ypz
*/

class Solution {
public:
    
    const vector<string> map = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    void backTracking(vector<string> &ans, string &cur, int flag, string &digits) {
        if(flag == digits.size()) ans.push_back(cur);
        if(flag < digits.size()) {
            for(auto c:map[digits[flag] - '2']) {
                cur[flag] = c;
                backTracking(ans, cur, flag + 1, digits);
            }
        }
    }
                
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if(digits.size() == 0) return result;
        string cur(digits.size(), '0');
        backTracking(result, cur, 0, digits);
        return result;
    }        
                
};
