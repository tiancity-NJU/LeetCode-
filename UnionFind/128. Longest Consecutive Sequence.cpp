

/*
  不用排序的方法找到最大的连续性问题，本质上就是个数字归类或者说聚类的问题，典型的并查集应用
*/


class Solution {
    
private:
      unordered_map<int,int>M;
      unordered_map<int,int>sz;
public:
    
    
    int Find(int x)
    {
        int now=x,root=x;
        while(M[root]!=root)
            root=M[root];
        int tmp;
        while(M[now]!=root)
        {
            tmp=M[now];
            M[now]=root;
            now=tmp;
        }
        
        return root;
    }
    
    
    int Union(int x,int y)
    {
        int rx=Find(x),ry=Find(y);
        if(rx==ry) return  sz[rx];
        if(sz[rx]<sz[ry])
        {
            M[rx]=ry;
            sz[ry]+=sz[rx];
            return sz[ry];
        }
        else
        {
            M[ry]=rx;
            sz[rx]+=sz[ry];
            return sz[ry];
        }
        return 0;
    }
    
    int longestConsecutive(vector<int>& nums) {
        
        if(nums.size()==0) return 0;
        for(int i=0;i<nums.size();i++)
        {
            M[nums[i]]=nums[i];
            sz[nums[i]]=1;
        }
        
        int MAX=1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>INT_MIN&&M.find(nums[i]-1)!=M.end())
            {
                MAX=max(MAX,Union(nums[i],nums[i]-1));
            }
            if(nums[i]<INT_MAX&&M.find(nums[i]+1)!=M.end())
            {
                MAX=max(MAX,Union(nums[i],nums[i]+1));
            }
        }
        
        return MAX;
    }
};
