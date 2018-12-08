
/*
  本身是个简单问题，但是以下解法却申请了大量没必要的空间，如果直接使用in-place 的方法会变得更加高效

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* p1=l1;
        ListNode* p2=l2;
        ListNode* start=NULL;
        ListNode* end=start;
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        if(p1->val<p2->val)
        {
            end=new ListNode(p1->val);
            p1=p1->next;
        }
        else
        {
            end=new ListNode(p2->val);
            p2=p2->next;
        }
        start=end;
        while(p1!=NULL&&p2!=NULL)
        {
            if(p1->val<p2->val)
            {
                end->next=new ListNode(p1->val);
                end=end->next;
                p1=p1->next;
            }
            else{
                end->next=new ListNode(p2->val);
                end=end->next;
                p2=p2->next;
            }
        }
        if(p1==NULL)
        {
            while(p2!=NULL)
            {
                end->next=new ListNode(p2->val);
                end=end->next;
                p2=p2->next;
            }
        }
        if(p2==NULL)
        {
            while(p1!=NULL)
            {
                end->next=new ListNode(p1->val);
                end=end->next;
                p1=p1->next;
            }
        }
        return start;
    }
};


/*
  没有额外空间的方法，直接修改指针，时间缩短了25%
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
       
        ListNode* result=new ListNode(0);
        ListNode* tmp=result;
        while(l1!=NULL||l2!=NULL)
        {
            if(l2==NULL||(l1!=NULL&&l1->val<=l2->val))
            {
                tmp->next=l1;
                l1=l1->next;
            }
            else
            {
                tmp->next=l2;
                l2=l2->next;
            }
            tmp=tmp->next;
        }
        return result->next;
    }
};
