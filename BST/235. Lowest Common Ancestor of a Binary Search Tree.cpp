

/*

  比较简单，如果p q在不同侧，则返回
  否则往对应的方向找

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
    
 
    
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        TreeNode* tmp=root;
        
        while(tmp!=NULL)
        {
            if(tmp->val==p->val || tmp->val==q->val) return tmp;
            if((tmp->val>p->val&&tmp->val<q->val) || (tmp->val>q->val&&tmp->val<p->val))
            {
                return tmp;
            }
            if(tmp->val<p->val)
            {
                tmp=tmp->right;
            }
            else
            {
                tmp=tmp->left;
            }
        }
        return tmp;
        
        
    }
};
