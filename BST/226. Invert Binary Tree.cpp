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
 写法一：
 author: ypz
 */
 
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return root;
        else if(root -> left == NULL && root -> right == NULL) return root;
        else if(root -> left == NULL && root -> right != NULL) {
            root -> left = invertTree(root -> right);
            root -> right = NULL;
        }
        else if(root -> left != NULL && root -> right == NULL) {
            root -> right = invertTree(root -> left);
            root -> left = NULL;
        }
        else {
            TreeNode* temp = root -> left;
            root -> left = invertTree(root -> right);
            root -> right = invertTree(temp);
        }
        return root;
    }
};

 /*
 写法二：
 author: ypz
 */

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return root;
        TreeNode* left = invertTree(root -> left);
        TreeNode* right = invertTree(root -> right);
        root -> left = right;
        root -> right = left;
        return root;
    }
};
