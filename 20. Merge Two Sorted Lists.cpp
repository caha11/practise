/** Did this problem before, forgot how to do it a bit. Logic was there, but coding wasn't that great. Forgot about lists.
**/

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
        ListNode *head_ans = new ListNode(0);
        
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        
        ListNode *current_node = head_ans;
        
        while(l1 && l2) {
            if(l1->val >= l2->val) {
                cout << "L2: " << l2->val << endl;
                current_node->next = l2;
                l2 = l2->next;
            } else {
                cout << "L1: " << l1->val << endl;
                current_node->next = l1;
                l1 = l1->next;
            }
            current_node = current_node->next;
        }
        current_node->next = l1 ? l1 : l2; 
        
        return head_ans->next;
    }
};
