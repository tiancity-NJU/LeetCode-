

/*
    本题不难，但是主要是要考虑完全越界的情况，以及如何保证代码的清晰和简洁

*/


class Solution {
public:
    int myAtoi(string str) {
        
		int base=0,i=0;
        int sign=1;
        while(i<str.size()&&str[i]==' ') i++;
        
        if(str[i]=='-' ||str[i]=='+')
        {
            if(str[i]=='-') sign=-1;
            i++;
        }
        
        while(i<str.size()&&(str[i]>='0'&&str[i]<='9'))
        {
            if(base>INT_MAX/10 || (base==INT_MAX/10&&str[i]-'0'>7))
                if(sign==1) return INT_MAX;
                else return INT_MIN;
            
            base*=10;
            base+=str[i]-'0';
            i++;
        }
        
        return sign*base;
        
        
        
        
    }
};
