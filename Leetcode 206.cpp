/**
206. Reverse Linked List
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = head, *n = head, *pre = NULL;
        while(n != NULL) {
            n = cur->next;
            cur->next=pre;
            pre = cur;
            cur = n;
        }
        return pre;
        
    }
};
