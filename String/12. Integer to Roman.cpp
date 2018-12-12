
/*
    第一种办法是很直接的利用if else 构成的从大到小的解析，但是这样运算效率非常低下，利用map的形式会更加直观
    author: ztc
*/

class Solution {
public:
    string intToRoman(int num) {
    string res = "";
		int i;
		int rep = 0;
		
		//  M
		rep = num / 1000;
		num = num % 1000;
		for (i = 0; i < rep; i++)
		{
			res += "M";
		}
		if (num / 100 == 9)    // 900
		{
			res += "CM";
			num -= 900;
		}

		//  D
		rep = num / 500;
		num = num % 500;
		for (i = 0; i < rep; i++)
		{
			res += "D";
		}
		if (num / 100 == 4)
		{
			res += "CD";
			num -= 400;
		}

		//  C
		rep = num / 100;
		num = num % 100;
		for (i = 0; i < rep; i++)
		{
			res += "C";
		}
		if (num / 10 == 9)
		{
			res += "XC";
			num -= 90;
		}

		// L
		rep = num / 50;
		num = num % 50;
		for (i = 0; i < rep; i++)
		{
			res += "L";
		}
		if (num / 10 == 4)
		{
			res += "XL";
			num -= 40;
		}

		//  X
		rep = num / 10;
		num = num % 10;
		for (i = 0; i < rep; i++)
		{
			res += "X";
		}
		if (num == 9)
		{
			res += "IX";
			num -= 9;
		}

		//  V
		rep = num / 5;
		num = num % 5;
		for (i = 0; i < rep; i++)
		{
			res += "V";
		}
		if (num == 4)
		{
			res += "IV";
			num -= 4;
		}

		for (i = 0; i < num; i++)
		{
			res += 'I';
		}
		return res;
    }
};


/*
      author: ypz
*/
class Solution {
public:
    string intToRoman(int num) {
        string s_string = "MDCLXVI";
        vector<int> s_int {1000,500,100,50,10,5,1};
        int index = 0;
        string result = "";
        int amount;
        while(num != 0){
            if(num * 10 < s_int[index]){
                index += 2;
                continue;
            }
            amount = num / s_int[index];
            if(amount >= 1 && amount <=3) result.append(amount, s_string[index]);
            else if(amount == 4){
                result.append(1, s_string[index]);
                result.append(1, s_string[index - 1]);
            }
            else if(amount == 5) result.append(1, s_string[index - 1]);
            else if(amount >= 6 && amount <= 8){
                result.append(1, s_string[index - 1]);
                result.append(amount - 5, s_string[index]); 
            } 
            else if(amount == 9){
                result.append(1, s_string[index]);
                result.append(1, s_string[index - 2]);
            }
            num = num % s_int[index];
            index += 2;
        }
        return result;
        
    }
};
