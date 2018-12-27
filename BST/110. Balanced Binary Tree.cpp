/*
左右子树中的节点需均满足高度差不小于1.
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
    int getLength(TreeNode* root) {
        if(root == NULL) return 0;
        else return max(getLength(root -> left), getLength(root -> right)) + 1;
    }
    
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        return abs(getLength(root -> left) - getLength(root -> right)) < 2  && isBalanced(root -> left) && isBalanced(root -> right);
    }
};

/*
换种写法。
author: ypz
*/

class Solution {
public:
    int getLength(TreeNode* root) {
        if(root == NULL) return 0;
        else return max(getLength(root -> left), getLength(root -> right)) + 1;
    }
    
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        else {
            if(abs(getLength(root -> left) - getLength(root -> right)) < 2) return isBalanced(root -> left) && isBalanced(root -> right);
            else return false;
        }
    }
};
