/** Problem is easy doing it the cyclical way **/


class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(!head) return NULL;
        
        ListNode* tail = head;
        int len = 1;
        
        while(tail->next != NULL) {
            tail = tail->next;
            len++;
        }
        
        tail->next = head;
        
        if(k %= len) {
            for(int i = 0; i < len - k; i++) tail = tail->next;
        }
        
        head = tail->next;
        tail->next = NULL;
        
        return head;        
    }
};
