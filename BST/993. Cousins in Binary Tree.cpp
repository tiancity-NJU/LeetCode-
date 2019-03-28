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
BFS，保存每一层节点与其父节的对，然后判断两个节点是否在同一层且父亲不同。
*/
class Solution {
public:
    void bfs(vector<vector<pair<TreeNode*, TreeNode*>>>& seq, TreeNode* root, int index, TreeNode* parent) {
        if(root == NULL) return;
        if(seq.size() <= index) {
            vector<pair<TreeNode*, TreeNode*>> temp;
            temp.push_back({root, parent});
            seq.push_back(temp);
        }
        else seq[index].push_back({root, parent});
        bfs(seq, root -> left, index+1, root);
        bfs(seq, root -> right, index+1, root);
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        if(root == NULL) return false;
        vector<vector<pair<TreeNode*, TreeNode*>>> seq;
        bfs(seq, root, 0, NULL);
        for(int i = 2; i < seq.size(); i++) {
            int ia = 101, ib = 101;
            for(int j = 0; j < seq[i].size(); j++){
                if(seq[i][j].first -> val == x) ia = j;
                if(seq[i][j].first -> val == y) ib = j;
            }
            if(ia != 101 && ib != 101 && seq[i][ia].second -> val != seq[i][ib].second -> val) return true;
        }
        return false;
    }
};
