
/*
  
  和上一题类似，但是树是无序的，但是树想要二叉排序会比较麻烦，因此对于一种散乱结构，只能尝试找到p和q的路径，然后返回最后一个相同的指针即可，因此
  我们需要先设置一个二维数组分别存储p和q的路径，然后遍历这个路径


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
    
    void Find(TreeNode* root,TreeNode* p,TreeNode* q,vector<TreeNode*>&tmp,vector<vector<TreeNode*>>&path)
    {
        if(root==NULL) return;
        
        tmp.push_back(root);
        if(root==p || root==q)
        {
            path.push_back(tmp);
        }
        
        Find(root->left,p,q,tmp,path);
        Find(root->right,p,q,tmp,path);
        tmp.pop_back();
        
    }
    
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        vector<vector<TreeNode*>>path;
        vector<TreeNode*>tmp;
        Find(root,p,q,tmp,path);
     
        for(int i=1;i<path[0].size()&&i<path[1].size();i++)
        {
            if(path[0][i]!=path[1][i]) return path[0][i-1];
        }
        
        if(path[0].size()<path[1].size()) return path[0].back();
        return path[1].back();
        
        
    }
};


/*
  还有一种思路是直接在函数上递归，如果自己不为p或者q，且在左孩子上找不到，则返回右孩子，反之同理

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
    
   TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==NULL) return root;
        if(root==p||root==q) return root;
        TreeNode* leftNode = lowestCommonAncestor(root->left,p,q);
        TreeNode* rightNode = lowestCommonAncestor(root->right,p,q);
        if(leftNode==NULL) return rightNode;
        if(rightNode==NULL) return leftNode;
        if(leftNode!=NULL&&rightNode!=NULL) return root;      
    }
};

