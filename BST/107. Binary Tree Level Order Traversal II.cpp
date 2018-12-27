/*
先从上到下，再翻转结果。
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
    void helper(vector<vector<int>>& ans, int pos, TreeNode* node) {
        if(node != NULL) {
            if(pos == ans.size()) ans.push_back({});
            ans[pos].push_back(node -> val);
            helper(ans, pos+1, node -> left);
            helper(ans, pos+1, node -> right);
        }
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        helper(ans, 0, root);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
