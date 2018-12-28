/*
将是否遍历过该节点存入字典。
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
    bool hasCycle(ListNode *head) {
        bool ans = false;
        map<ListNode*, bool> dict;
        while(head != NULL) {
            auto it = dict.find(head);
            if(it == dict.end()) dict[head] = false;
            else {
                //dict[head] = true;
                ans = true;
                break;
            }
            head = head -> next;
        }
        return ans;
    }
};
