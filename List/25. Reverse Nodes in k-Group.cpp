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
            // k-1次操作
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


/*
   链表题目难度不大，主要就是比较绕，这一题的难点在于K>2时如何反转的情况，并且注意如果不足K个元素，则不翻转
   为了条理更加清晰，我们可以设计一个翻转函数，一个参数是待翻转数组的前一个元素first，另一个参数是待翻转数组的最后一个元素end
   并且设置3个临时指针，循环翻转(注意区分k=1时无法构建这三个指针)，最后返回下一个待翻转部分的first即可
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
    
    
private:
    
    ListNode* rever(ListNode*first,ListNode*end)
    {
        if(first==NULL||end==NULL) return NULL;
        ListNode*tmp1=first->next,*tmp2=tmp1->next,*tmp3=tmp2->next;
        while(tmp2!=end)
        {
            tmp2->next=tmp1;
            tmp1=tmp2;
            tmp2=tmp3;
            tmp3=tmp3->next;
        }
        tmp2->next=tmp1;
        first->next->next=tmp3;
        ListNode*ret=first->next;
        first->next=tmp2;
        return ret;
    }
    
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
       
        if(k==1) return head;
        
        ListNode* newhead=new ListNode(0);
        newhead->next=head;      
        ListNode* first=newhead,*end=newhead;
    
        while(end!=NULL)
        {
            end=first;
            for(int i=0;i<k;i++)
            {
                if(end!=NULL)
                    end=end->next;
            }
            if(end==NULL) return newhead->next;
            first=rever(first,end);
        }
        return newhead->next;
    }
};
