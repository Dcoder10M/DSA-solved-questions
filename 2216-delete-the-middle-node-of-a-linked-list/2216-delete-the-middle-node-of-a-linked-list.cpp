/**
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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* slow=new ListNode(0);ListNode *fast=head;
        slow->next=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        // slow->val=slow->next->val;
        if(slow->next==head)return head->next;
        slow->next=slow->next->next;
        return head;
    }
};