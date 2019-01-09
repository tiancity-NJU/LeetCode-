/*
  最简单的方法当然就是中序遍历，记录下扫描过的节点以及对应对应的值，然后排序后回填，空间复杂度O(n)
  另外一种直接交换的没太明白
*/


 void recoverTree(TreeNode* root) {
        vector<TreeNode*> nodes;
        vector<int> vals;
        
        inorder(root, nodes, vals);
        sort(vals.begin(), vals.end());
        for (int i = 0; i < vals.size(); i++)
            nodes[i]->val = vals[i];
    }
    
    void inorder(TreeNode* root, vector<TreeNode*>& nodes, vector<int>& vals) {
        if (root == NULL)
            return;
        inorder(root->left, nodes, vals);
        nodes.push_back(root);
        vals.push_back(root->val);
        inorder(root->right, nodes, vals);
    }
