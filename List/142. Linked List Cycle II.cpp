/*
思路同141题，只不过返回值不同。
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
    ListNode *detectCycle(ListNode *head) {
        bool flag = false;
        ListNode *ans;
        if(head == NULL || head -> next == NULL) return NULL;
        map<ListNode*, bool> dict;
        while(head != NULL) {
            auto it = dict.find(head);
            if(it == dict.end()) dict[head] = false;
            else {
                ans = head;
                flag = true;
                break;
            }
            head = head -> next;
        }
        if(flag == false) ans = NULL;
        return ans;
    }
};



/*
    判环问题第二问，不仅要判断是否成环，还需要找到环入口位置，利用Floyd算法，第一步和上一问一样，先判断是否有环
    接着将一个指针指向head，一个指针指向相遇点，每次前进一步，再次相遇位置即为入口
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
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL || head->next==NULL) return NULL;
        
        ListNode *slow=head,*fast=head;
        
        while(fast!=NULL&&fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            
            if(fast==slow) break;
        }
        if(fast!=slow) return NULL;
        
        slow=head;
        while(slow!=fast)
        {
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
        
    }
};
