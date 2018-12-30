/*
当层数为奇数时，将新元素插入到数组的开始即可。
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
    void helper(vector<vector<int>>& ans, TreeNode* node, int level) {
        if(node == NULL) return;
        if(ans.size() == level) {
            vector<int> temp;
            temp.push_back(node -> val);
            ans.push_back(temp);
        }
        else {
            if(level % 2 == 0) ans[level].push_back(node -> val);
            else ans[level].insert(ans[level].begin(), node -> val);
        }
        helper(ans, node -> left, level + 1);
        helper(ans, node -> right, level + 1);
    }
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        helper(ans, root, 0);
        return ans;
    }
};
