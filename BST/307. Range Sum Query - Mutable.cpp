
/*

  本来以为这种问题可以通过维护一个sum函数轻松解决，但是运行速度高达 100+ms，似乎可以用二叉树的形式解决，后续更新，先提供一个简单版本


*/

class NumArray {
private:
    vector<int>nums;
    vector<int>sum;
public:
    NumArray(vector<int> nums) {
        if(nums.size()==0) return;
        this->nums.assign(nums.begin(),nums.end());
        sum.push_back(0);
        for(int i=0;i<nums.size();i++)
        {
            sum.push_back(sum[i]+nums[i]);
        }
    }
    
    void update(int i, int val) {
        int delta=val-nums[i];
        nums[i]=val;
        for(;i<sum.size();i++)
            sum[i+1]+=delta;
    }
    
    int sumRange(int i, int j) {
        return sum[j+1]-sum[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
