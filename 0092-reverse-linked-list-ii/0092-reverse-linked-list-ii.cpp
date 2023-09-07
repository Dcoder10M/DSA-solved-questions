class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head)   return NULL;
        if(!head->next) return head;

        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prev = dummy;

        for(int i = 0; i < left - 1; i++)    prev = prev->next;
        ListNode *curr = prev->next;

        for(int i = 0; i < right - left; i++)
        {
            ListNode *forw = curr->next;
            curr->next = forw->next;
            forw->next = prev->next;
            prev->next = forw;
        }
        return dummy->next;

        
        
    }
};