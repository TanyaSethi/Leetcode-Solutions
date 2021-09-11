/**
19. Remove Nth Node From End of List
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head, *slow = head, *prev = NULL;
        if(head -> next == NULL)
            return NULL;
        for(int i=1; i<n; i++) {
            if(fast->next != NULL)
                fast = fast -> next;
        }
        while(fast->next != NULL) {
            fast = fast->next;
            prev = slow;
            slow = slow->next;   
        }
        if(prev == NULL) {
            head = head -> next;
            return head;
        }
        prev -> next = slow -> next;
        // free(slow);
        return head;
    }
};
