
/*
  每次新建preorder在l1位置的元素，然后在inorder中寻找，中间分开，注意 l 和 r 是左闭右开
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
    
    TreeNode* build(vector<int>&preorder,vector<int>&inorder,int l1,int r1,int l2,int r2)
    {
        if(l1>=r1 || l2>=r2) return NULL;
        TreeNode* root=new TreeNode(preorder[l1]);
        int pos=0;
        for(;pos+l2<r2&&inorder[pos+l2]!=preorder[l1];pos++);
        
        if(pos+l2>l2)
        {
            root->left=build(preorder,inorder,l1+1,l1+pos+1,l2,l2+pos);
        }
        if(pos+l2<r2)
        {
            root->right=build(preorder,inorder,l1+pos+1,r1,l2+pos+1,r2);
        }
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
       
        if(preorder.size()==0 || inorder.size()==0) return NULL;
        TreeNode* root=build(preorder,inorder,0,preorder.size(),0,inorder.size());
        return root;
    }
};

/*
  另外一种是使用字典，本质差不多
*/


class Solution {
public:
    map<int,int>M;
    int k;
    TreeNode*Helper(vector<int>& preorder, vector<int>& inorder,int first,int end,int &k){
       
        if(first>end) return NULL;
        TreeNode* root=new TreeNode(preorder[k]);
        int pos=M[preorder[k]];
        if(pos>first)
            root->left=Helper(preorder,inorder,first,pos-1,++k);
        if(pos<end)
            root->right=Helper(preorder,inorder,pos+1,end,++k);
        
        return root; 
    }
    
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty()){
            return NULL;
        }
        int length = preorder.size();
        for(int i=0;i<inorder.size();i++)
            M[inorder[i]]=i;
        
        k=0;
        TreeNode *result=Helper(preorder,inorder,0,length-1,k);
        return result;
        
    }
};
