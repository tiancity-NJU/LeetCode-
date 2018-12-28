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
