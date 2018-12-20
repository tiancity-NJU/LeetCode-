

/*
  思路挺简单，但是过程很多容易犯错的地方，包括参数的设置，边界条件的判断，由于num.size()=op.size()+1 可以利用这一点，分别存储向量
  然后回溯
*/


class Solution {

private:
    vector<int>num;
    vector<int>op;
public:
    
    int operate(int left){
    if(op[left] == '+') return num[left] + num[left+1];
    if(op[left] == '-') return num[left] - num[left+1];
    if(op[left]=='*') return num[left]*num[left+1];
}

int operateWithValues(int val1, int val2, int index){
    if(op[index] == '+') return val1 + val2;
    if(op[index] == '-') return val1 - val2;
    if(op[index]=='*') return val1*val2;
}
    
    vector<int> comp(int l,int r)
    {
        vector<int>left,right;
        vector<int>ans;
        if(abs(l-r) <= 0) return ans;
    
    
        if(abs(l-r) == 1){
            ans.push_back(num[l]);
            return ans;
        }
    
    if(abs(l-r) == 2){
        //if value is only size two then return operation of both
        ans.push_back(operate(l));
        return ans;
    }
        
    for(int pivot=l+1; pivot<r; ++pivot){
        left = comp(l, pivot);
        right = comp(pivot, r);
    
        //take two resulting vectors and create a third vector containing all the values and combine
        
        for(int i=0; i<left.size();++i){
            for(int j=0; j<right.size();++j){
                int val = operateWithValues(left[i],right[j],pivot-1);
                ans.push_back(val);          
            }
        }
    }
        return ans;
    }
    
    
    vector<int> diffWaysToCompute(string input) {
        
        
        int i=0;
        while(i<input.size())
        {
            if(input[i]=='+' || input[i]=='-' || input[i]=='*')
            {
                op.push_back(input[i]);
                i++;
                continue;
            }
            int tmp=0;
            while(i<input.size()&&input[i]<='9'&&input[i]>='0')
            {
                tmp*=10;
                tmp+=input[i]-'0';
                i++;
            }
            num.push_back(tmp);
        }
        
        vector<int>ans;
        int M=num.size(),N=op.size();
        
        return comp(0,M);
                
    
    }
};
