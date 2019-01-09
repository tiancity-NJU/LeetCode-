

/*
  利用一个hall指针引用来保留链式的最后一个位置，注意使用  * & 否则在 sub(right,hall) 用的还是原来的hall
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
    
    void sub(TreeNode*root,TreeNode* &hall)
    {
        if(root==NULL) return;        
        hall->right=root;
        hall->left=NULL;
        hall=hall->right;
        TreeNode* left=root->left;
        TreeNode* right=root->right;
        sub(left,hall);
        sub(right,hall);
    }
    
    void flatten(TreeNode* root) {
        
        TreeNode* head=new TreeNode(0);
        sub(root,head);
         
    }
};
