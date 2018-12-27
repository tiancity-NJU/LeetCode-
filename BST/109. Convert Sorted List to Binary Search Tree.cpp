/*
将链表转化为数组，然后采用上一题的思路。
author: ypz
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
    vector<int> listToArray(ListNode* head) {
        vector<int> array;
        while(head != NULL) {
            array.push_back(head -> val);
            head = head -> next;
        }
        return array;
    }
    
    TreeNode* helper(vector<int>& nums, int left, int right) {
        if(left >= right) return NULL;
        int mid = (left + right) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        node -> left = helper(nums, left, mid);
        node -> right = helper(nums, mid+1, right);
        return node;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> list = listToArray(head);
        return helper(list, 0, list.size());
    }
};
