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
采用递归。
author: ypz
*/

class Solution {
public:
    void tree(TreeNode* root, vector<int>& ans) {
        if(root != NULL) {
            if(root -> left != NULL) tree(root -> left, ans);
            ans.push_back(root -> val);
            if(root -> right != NULL) tree(root -> right, ans);
        }   
    }
        
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        tree(root, ans);
        return ans;
    }
};
