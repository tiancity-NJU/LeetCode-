

/*
  和上题第二种方法一样，参考了别人的方法

*/

class Solution {
public:
    map<int,int>m;
    TreeNode*Helper(vector<int>& inorder, vector<int>& postorder,int first, int end,int pos,int cur){
        TreeNode*result = new TreeNode(postorder[cur]);
        int temp = m[postorder[cur]];
        if(temp>first) result->left = Helper(inorder,postorder,first,temp-1,pos,pos+temp-first-1);
        if(temp<end)   result->right = Helper(inorder,postorder,temp+1,end,pos+temp-first,cur-1);
        return result;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.empty()) return NULL;
        int length=inorder.size();
        for(int i=0;i<length;i++){
            m.insert(pair<int,int>(inorder[i],i));
        }
        return Helper(inorder,postorder,0,length-1,0,length-1);
    }
};
