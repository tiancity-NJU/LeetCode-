
/*

  如果没有各种限制，有很多方法，比较交换数值之类，但是题目要求我们只能直接对链表进行操作，涉及到这种反转，需要存储三个指针 父指针，待交换的第一个指针
  待交换的第二个指针 ，接下来就是一些链表操作了，直到first second有一个变成 NULL， 另外注意 head为空的情况

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
    ListNode* swapPairs(ListNode* head) {
       	
		ListNode* new_head=new ListNode(0);
        new_head->next=head;
        
        if(head==NULL) return head;
        ListNode* current=new_head;
        ListNode* first=new_head->next,*second=head->next;
        while(first!=NULL&&second!=NULL)
        {
            first->next=second->next;
            second->next=first;
            current->next=second;
            current=first;
            first=current->next;
            if(first!=NULL) second=first->next;
        }
        
        return new_head->next;
    }
};
