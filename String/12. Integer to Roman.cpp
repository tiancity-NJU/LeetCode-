
/*
    第一种办法是很直接的利用if else 构成的从大到小的解析，但是这样运算效率非常低下，利用map的形式会更加直观

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
      利用 unordered_map 的形式进行解决
*/
