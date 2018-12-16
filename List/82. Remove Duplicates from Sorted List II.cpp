/*
  本实现还不是最优的，增加了一些无用的条件判断，但是对于时间复杂度没有造成影响，解决List的问题，特别是涉及到头指针修改的问题，常用思路
  就是增加一个临时头指针指向head，这样就将整个List同等对待
  author: ztc  
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL||head->next==NULL) return head;
        ListNode* new_head=new ListNode(head->val-1);
        new_head->next=head;
        ListNode*before=new_head;
        ListNode*after=head;
        while(after!=NULL)
        {
            if(after->next!=NULL&&after->val==after->next->val)
            {
                int tmp=after->val;
                while(after!=NULL&&after->val==tmp) after=after->next;
                before->next=after;
            }
            else
            {
                if(before!=NULL) before=before->next;
                if(after!=NULL) after=after->next;
            }
            
        }
        return new_head->next;
    }
};


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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) return head;
        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        ListNode* curr = dummy;
        ListNode* temp = curr -> next;
        while(temp != NULL && temp -> next != NULL) {
            if(temp -> next -> val == temp -> val){
                ListNode* nxxt = temp -> next;
                while(nxxt != NULL && nxxt -> val == temp -> val) {
                    nxxt = nxxt -> next;
                    temp = temp -> next;
                }
                curr -> next = nxxt;
                temp = curr -> next;
            }
            else {
                curr = curr -> next;
                temp = curr -> next;
            }
        }
        return dummy -> next;
    }
};
