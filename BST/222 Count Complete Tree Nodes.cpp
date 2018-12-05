
/*

  对于常规的树，要统计所有结点，最容易想到的就是统计左子树+右子树+1，这样时间复杂度



*/

class Solution {
public:
    
    
   
    int countNodes(TreeNode* root) {
        
        if(root==NULL) return 0;
        int countLeft=0,countRight=0;
        TreeNode* left=root,*right=root;
        
        while(left!=NULL) {left=left->left;countLeft++;}
        while(right!=NULL) {right=right->right;countRight++;}
        
        
        if(countLeft==countRight) return pow(2,countLeft)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};
