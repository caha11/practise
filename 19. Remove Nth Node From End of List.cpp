/** Good solution, 100% faster than everyone elses.
	Things to improve: THINK LONGER ABOUT EDGE CASES.
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        // Edge case 1 - Head is NULL
        if(head == NULL) return NULL;
        // Edge case 2 - List size is 1, and n is 1.
        if(n == 1 && head->next == NULL) return NULL;
        
        int list_size = 1;
        
        ListNode *current_node = head;
        while(current_node->next != NULL) {
            current_node = current_node->next;
            list_size++;
        }
        
        // Edge case 3 - n is higher than the list size.
        if(n > list_size) return NULL;
        
        // Edge case 4 - n equals to start of list.
        if(n == list_size) {
            head = head->next;
            return head;
        }
        
        int list_iterations = list_size - n;
        
        int count_iterations = 1;
        current_node = head;
        while(current_node->next != NULL) {
            if(count_iterations == list_iterations) {
                if(current_node->next->next != NULL) {
                    //cout << current_node->val << " : " << current_node->next->val << endl;
                    current_node->next = current_node->next->next;
                    return head;
                } else {
                    current_node->next = NULL;
                    return head;
                }
            }
            current_node = current_node->next;
            count_iterations++;
        }
        return head;
    }
};
