/**
 
 
 21. Merge Two Sorted Lists
 
 
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
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        ListNode *temp = new ListNode(0);
        ListNode *head3 = temp;
        while(head1 != NULL && head2 != NULL) {
            if(head1 -> val < head2 -> val) {
                head3 -> next = head1;
                head1 = head1 -> next;
            }
            else if(head1 -> val >= head2 -> val) {
                head3 -> next = head2;
                head2 = head2 -> next;
            }
            head3 = head3->next;
        }
        
        if(head1 != NULL) {
            head3 -> next = head1;
        }
        if(head2 != NULL) {
            head3 -> next = head2;
        }
        return temp -> next;
    }
};
