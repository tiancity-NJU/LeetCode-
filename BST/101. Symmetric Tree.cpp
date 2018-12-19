/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 /*
 利用递归。
 author: ypz
 */
 
class Solution {
public:
    bool isMirror(TreeNode* root1, TreeNode* root2) {
        if(root1 == NULL && root2 == NULL) return true;
        else if(root1 == NULL || root2 == NULL) return false;
        else{
            if(root1 -> val == root2 -> val) return isMirror(root1 -> left, root2 -> right) && isMirror(root1 -> right, root2 -> left);
            else return false;
        }
    }
    
    bool isSymmetric(TreeNode* root) {
        return isMirror(root, root);
    }
};
