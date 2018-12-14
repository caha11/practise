/** 
 * Basically used the solution provided. 
 * Was thinking to reverse the list but it's inefficient.
 * Can just use basic math, add up numbers and keep track of the carry over number.
**/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode *head = new ListNode(0);
        ListNode *list1 = l1, *list2 = l2, *curr = head;
        int carry = 0;
        
        while(list1 != NULL || list2 != NULL) {
            int x = (list1 != NULL) ? list1->val : 0;
            int y = (list2 != NULL) ? list2->val : 0;
            int sum = x + y + carry;
            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
            if(list1 != NULL) list1 = list1->next;
            if(list2 != NULL) list2 = list2->next;
        }
        
        if(carry > 0) {
            curr->next = new ListNode(carry);
        }
        return head->next; 
    }
};