
/*

  对于常规的树，要统计所有结点，最容易想到的就是统计左子树+右子树+1，但是这样会 超时
  
  能够想到的就是在其中加入一个终止条件，防止大量没必要的递归，如果左子树的深度等于右子树的深度，那么这个子树是个完全的，就没必要递归了



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
