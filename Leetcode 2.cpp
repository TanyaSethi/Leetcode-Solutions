/**

2. Add Two Numbers


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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head3= new ListNode();
        ListNode* l3 = head3;
        int carry = 0, sum = 0, x, y;
        
        while(l1 != NULL || l2 != NULL) {
            x = (l1 != NULL) ? l1 -> val : 0;
            y = (l2 != NULL) ? l2 -> val : 0;
           
            sum = x + y + carry;
           
            carry = sum / 10;
            sum = sum % 10;
            
            l3 -> next = new ListNode(sum);
             
            l3 = l3->next;    
            if(l1 != NULL)
                l1 = l1->next;  
            if(l2  != NULL)
                l2 = l2->next;  
        }
        if(carry > 0)
            l3->next = new ListNode(carry);
    
        return head3->next;
    }
};
