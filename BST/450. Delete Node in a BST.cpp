
/*
  关键在于理清二叉树如何删除操作
  若该节点没有孩子或者只有一个孩子，很好删
  对于有两个孩子的情况，将它与右孩子的最左子孙数值交换，接着到右边删除该数即可

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
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if(root==NULL) return root;
        if(root->val<key)
        {
            root->right=deleteNode(root->right,key);
        }
        else if(root->val>key)
        {
            root->left=deleteNode(root->left,key);
        }
        else
        {
            if(root->left==NULL && root->right==NULL)
            {
                delete(root);
                return NULL;
            }
            if(root->left==NULL || root->right==NULL)
            {
                TreeNode* ans=root->left?root->left:root->right;
                delete(root);
                return ans;
            }
            else
            {
                TreeNode* tmp=root->right;
                while(tmp->left)
                    tmp=tmp->left;
                root->val=tmp->val;
                root->right=deleteNode(root->right,tmp->val);
            }
        }
        return root;
        
    }
};
