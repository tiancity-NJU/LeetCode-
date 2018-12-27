/*
author: ypz
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
    bool helper(TreeNode* node, int temp, int sum) {
        if(node == NULL && temp == sum) return true;
        else if(node == NULL) return false;
        else {
            if(node -> left != NULL && node -> right != NULL) return helper(node -> left, temp + node -> val, sum) || helper(node -> right, temp + node -> val, sum);
            else if(node -> left != NULL) return helper(node -> left, temp + node -> val, sum);
            else return helper(node -> right, temp + node -> val, sum);
        }
    }
    
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL) return false;
        return helper(root, 0, sum);
    }
};
