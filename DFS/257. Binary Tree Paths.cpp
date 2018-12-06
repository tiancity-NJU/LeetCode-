


/*

  典型的DFS题，没什么难度，容易出错的一点就是在递归时不能到root==NULL才结束，这样的话，同一个答案就会压入两遍，到达叶子节点就要压入


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
    
    void vis(TreeNode* root,vector<int>&tmpAns,vector<string>&res)
    {
        
        if(root->left==NULL&&root->right==NULL)
        {
            tmpAns.push_back(root->val);
            string s="";
            if(tmpAns.size()!=0) s=to_string(tmpAns[0]);
            for(int i=1;i<tmpAns.size();i++)  s+="->"+to_string(tmpAns[i]);
            res.push_back(s);
            tmpAns.pop_back();
            return;
        }
        
        tmpAns.push_back(root->val);
        if(root->left!=NULL) vis(root->left,tmpAns,res);
        if(root->right!=NULL) vis(root->right,tmpAns,res);
        tmpAns.pop_back();
        
        
        
    }
    
    
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>res;
        vector<int>tmpAns;
        if(root==NULL) return res;
        vis(root,tmpAns,res);
        return res;
    }
};
