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
 author: ypz
 从上到下递归。
 */
 
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0 || inorder.size() == 0)
            return NULL;
        int index = 0;
        TreeNode* tree = new TreeNode(preorder[0]);
        vector<int> preleft, preright, inleft, inright;
        while(inorder[index] != preorder[0])
            index++;
        for(int i = 0; i < index; i++) {
            preleft.push_back(preorder[i+1]);
            inleft.push_back(inorder[i]);
        }
        for(int i = index + 1; i < preorder.size(); i++) {
            preright.push_back(preorder[i]);
            inright.push_back(inorder[i]);
        }
        tree -> left = buildTree(preleft, inleft);
        tree -> right = buildTree(preright, inright);
        return tree;
    }
};
