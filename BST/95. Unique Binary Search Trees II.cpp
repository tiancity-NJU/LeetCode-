

/*
  
  感觉比较难的一个题目，虽然想到必然需要递归的方式解决，但是一个子结构的解法却很难想出来，我们不妨来考虑根节点
  倘若根节点是  k+1  那么左子树是 k个结点所有组合的情况，右子树是n-k-1个子树的所有情况，两种情况乘起来的 Case 则代表 k+1 为根时所有子树的个数，
  因此必定有一个二层循环 每一次都要构造一个  node(k+1) 然后把左子树和右子树的情况用数组的形式遍历添加。然后对于子树重复这一过程，得到CaseLeft即
  为上层的一边子树情况 ！！！
  总结来说，对于其中任意节点：
  1.判断叶子结点的终止条件，返回空
  2.遍历自身取值范围 
  3.对于自身取值的每一个情况，左右子树的节点数就确定了，然后可以递归进入子树，返回一个Case长度的root指针
  4.对于CaseRight和CaseLeft的两两组合，构建该函数根节点的指针，形成一个CaseLeft*CaseRight长度的一个子树，返回结果

*/








/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    vector<TreeNode*>Find(int s,int n)
    {
        vector<TreeNode*>ans;
        if(n==0) {ans.push_back(NULL);return ans;}
        if(n==1){ans.push_back(new TreeNode(s)); return ans;}

        for(int k=0;k<n;k++)
        {
            vector<TreeNode*> left=Find(s,k);
            vector<TreeNode*> right=Find(s+k+1,n-k-1);
            for(int i=0;i<left.size();i++)
                for(int j=0;j<right.size();j++)
                {
                    TreeNode* root=new TreeNode(s+k);
                    root->left=left[i];
                    root->right=right[j];
                    ans.push_back(root);
                }
        }
        return ans;
    
    }
    
    
    
    vector<TreeNode*> generateTrees(int n) {
       
        vector<TreeNode*>ans;
        if(n==0) return ans;
        
        int start=1;
        return Find(start,n);
    }
};
