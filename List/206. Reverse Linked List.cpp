/*
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
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head -> next == NULL) 
            return head;
        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        ListNode* pre = dummy -> next;
        ListNode* cur = pre -> next;
        pre -> next = NULL;
        while(cur != NULL) {
            ListNode* nxt = cur -> next;
            cur -> next = pre;
            pre = cur;
            cur = nxt;
        }
        dummy -> next = pre;
        
        return dummy -> next;
    }
};
