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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(k < 2) return head;
        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        ListNode* pre = dummy;
        ListNode* cur = dummy;
        int length = 0;
        while(cur -> next != NULL) {
            length++;
            cur = cur -> next;
        }
        
        while(k <= length) {
            // cur对应的值始终不变，nxt与tmp分别为cur后一位和后两位
            cur = pre -> next;
            for(int i = 0; i < k - 1; i++) {
                ListNode* nxt = cur -> next;
                ListNode* tmp = nxt -> next;
                cur -> next = tmp;
                nxt -> next = pre -> next;
                pre -> next = nxt;
            } 
            pre = cur;
            length = length - k;
        }
        return dummy -> next;
        
    }
};
