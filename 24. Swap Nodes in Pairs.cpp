/** A bit slow in creating the solution. Need more practise.
	Improve: check for all edge cases
			 practise more on lists.
			 check for syntax errors more.

	Good:    came up with a solution independently
			 commented well.
**/

// My solution that caused run time error for some reason.
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
    ListNode* swapPairs(ListNode* head) {
        
        if(head == NULL) return NULL;
        if(head->next == NULL) return head;
        
        ListNode *swap_node_1 = head;
        ListNode *swap_node_2 = head->next;
        head = swap_node_2;
        
        ListNode *tmp_last;
        
        while(swap_node_1->next != NULL) {
            
            // The swap is happening here.
            ListNode *tmp_next = swap_node_2->next;
            swap_node_2->next = swap_node_1;
            swap_node_1->next = tmp_next;
            
            // Link last pair to this pair.
            if(tmp_last != NULL) {
                tmp_last->next = swap_node_2;
            }
            
            tmp_last = swap_node_1;
            
            // Check if there is only 1 node left.
            if(swap_node_1->next == NULL) break;
            if(swap_node_1->next->next == NULL) break;
            
            // Transitions to next.
            swap_node_1 = swap_node_1->next;
            swap_node_2 = swap_node_1->next;
            
        }
        return head;
    }
};

