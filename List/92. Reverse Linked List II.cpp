

/*
    本身难度不大，但是链表的问题主要就是细节，需要多少个指针，如果处理边界情况，防止空指针等问题
    首先找到待翻转部分的前一个指针start和翻转部分的最后一个指针end，分两种情况：
     start->next=end  只差一个 那么不用翻转
     设置3个指针 tmp1->tmp2->tmp3   需要tmp1<-tmp2 tmp3  再依次往后移动一位，直到tmp2==end，中间部分都翻转完成，现在只需要首尾
     缝合即可
     主要end!=NULL,这样的话能够保证tmp1 tmp2 不可能为空
     另外一题group 翻转方法也是一样，不断调用这个函数即可。
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
    
    void rever(ListNode*start,ListNode*end)
    {
        if(start==NULL||end==NULL) return;
        if(start->next==end) return;
//         if(start->next->next==end)
//         {
//             start->next->next=end->next;
//             end->next=start->next;
//             start->next=end;
//             return;
//         }
        
        ListNode*tmp1=start->next,*tmp2=tmp1->next,*tmp3=tmp2->next;
        while(tmp2!=end)
        {
            tmp2->next=tmp1;
            tmp1=tmp2;
            tmp2=tmp3;
            tmp3=tmp3->next;
        }
        tmp2->next=tmp1;
        start->next->next=tmp3;
        start->next=tmp2;
    }
    
    
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        
        if(m>=n) return head;
        ListNode*newhead=new ListNode(0);
        newhead->next=head;
        
        ListNode*start=newhead;
        int pos=1;
        while(start!=NULL&&pos<m)
        {
            start=start->next;
            pos++;
        }
        ListNode*end=start;
        while(end!=NULL&&pos<n+1)
        {
            end=end->next;
            pos++;
        }
       
        rever(start,end);
        
        return newhead->next;
    }
};
