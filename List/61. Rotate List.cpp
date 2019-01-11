/*
先将链表成环，再断开。
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || k == 0) return head;
        int len = 1;
        ListNode* node1 = head;
        ListNode* node2 = head;
        while(node2 -> next != NULL) {
            node2 = node2 -> next;
            len++;
        }
        node2 -> next = head;
        k = k % len;
        if(k != 0) {
            for(int i = 0; i < len - k; i++) node2 = node2 -> next;
        }
        node1 = node2 -> next;
        node2 -> next = NULL;
        return node1;
    }
};
