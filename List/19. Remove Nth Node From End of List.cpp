
/*
  
    最简单的思路，就是先扫描一遍，统计长度，然后求得正向的距离
    但是无法满足一次pass的要求，因此采用双指针的方式
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len=0;
        ListNode*tmp(0);
        ListNode*del(0);
        for(tmp=head;tmp!=NULL;tmp=tmp->next)
        {
            len+=1;
        }
        int pos=len-n;
        
        if(pos==0)
        {
            tmp=head->next;
            delete(head);
            head=tmp;
        }
        else{
            tmp=head;
            while(--pos>0)
            {
                tmp=tmp->next;
            }
            del=tmp->next;
            tmp->next=del->next;
            delete(del);
        }
       return head; 
    }
};


/*
  采用双指针可以通过一次遍历即可删除
  首先，对于删除问题，为了不像以上方法这种分别考虑，我们都需要加入虚拟头结点，然后维护两个指针，设置n为启动倒计时，n<0时 P2才开始移动，这样就能
  保证P1 P2相距 n即可，但是经过测试，这种方法好像比先扫描一遍还要慢

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* new_head=new ListNode(0);
        new_head->next=head;
        ListNode* p1=new_head,*p2=new_head;
        while(p1->next!=NULL)
        {
            p1=p1->next;
            n--;
            if(n<0) p2=p2->next;
        }
        p2->next=p2->next->next;
        return new_head->next;
    }
};
