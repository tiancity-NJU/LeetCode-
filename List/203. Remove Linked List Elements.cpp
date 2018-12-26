/*
易错点：line24不要忘记加else
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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL) return head;
        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        ListNode* cur = dummy;
        while(cur -> next) {
            ListNode* temp = cur -> next;
            if(temp -> val == val) cur -> next = temp -> next;
            else cur = cur -> next;
        }
        return dummy -> next;
    }
};
