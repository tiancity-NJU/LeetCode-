/*
author: ypz
先反转后半段链表，在与前半段逐一比较是否相同。
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
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head -> next == NULL)
            return true;
        ListNode* slow = head;
        ListNode* fast = head -> next;
        
        while(fast != NULL && fast -> next != NULL) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        ListNode* prev = slow;
        ListNode* half = slow -> next;
        slow -> next = NULL;
        
        while(half != NULL) {
            ListNode* nxt = half -> next;
            half -> next = prev;
            prev = half;
            half = nxt;
        }

        while(head != NULL && prev != NULL) {
            if(head -> val != prev -> val)
                return false;
            head = head -> next;
            prev = prev -> next;
        }
        return true;
    }
};
