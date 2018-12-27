/*
采用DFS。
author: ypz.
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
    void helper(vector<vector<int>>& ans, vector<int>& list, TreeNode* node, int sum) {
        if(node -> left == NULL && node -> right == NULL && node -> val == sum) {
            list.push_back(node -> val);
            ans.push_back(list);
        }
        else if(node -> left == NULL && node -> right == NULL) return;
        else {
            vector<int> list1(list);
            list1.push_back(node -> val);
            if(node -> left != NULL) helper(ans, list1, node -> left, sum - node -> val);            
            vector<int> list2(list);
            list2.push_back(node -> val);
            if(node -> right != NULL) helper(ans, list2, node -> right, sum - node -> val);
        }
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ans;
        vector<int> list;
        if(root != NULL) helper(ans, list, root, sum);
        return ans;
    }
};
