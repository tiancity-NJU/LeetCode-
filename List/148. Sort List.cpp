/*
采用归并排序。
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
    ListNode* getMid(ListNode* head, ListNode* tail) {
        if(head == tail) return head;
        ListNode* p1 = head;
        ListNode* p2 = head;
        while(p1 != NULL && p2 != NULL && p2 -> next != NULL && p2 -> next -> next != NULL) {
            p1 = p1 -> next;
            p2 = p2 -> next -> next;
        }
        return p1;
    }
    
    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        while(left != NULL && right != NULL) {
            if(left -> val < right -> val) {
                cur -> next = left;
                left = left -> next;
            }
            else {
                cur -> next = right;
                right = right -> next;
            }
            cur = cur -> next;
        }
        if(left != NULL) cur -> next = left;
        else cur -> next = right;
        return dummy -> next;
    }
    
    ListNode* getPartition(ListNode* head, ListNode* tail) {
        if(head == tail) return head;
        ListNode* mid = getMid(head, tail);
        ListNode* right = getPartition(mid -> next, tail);
        mid -> next = NULL;
        ListNode* left = getPartition(head, mid);
        return merge(left, right);
    }
    
    ListNode* sortList(ListNode* head) {
        if(head == NULL) return head;
        ListNode* tail = head;
        while(tail -> next != NULL) tail = tail -> next;
        return getPartition(head, tail);
        
    }
};
