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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> arr;
        while(head){
            arr.push_back(head->val);
            head=head->next;
        }
        stack<int> st;
        vector<int> ans;
        for(int i=arr.size()-1;i>=0;i--){
            if(st.empty()){
                ans.push_back(0);
                st.push(arr[i]);
            }else{
                while(!st.empty() && arr[i]>=st.top()){
                    st.pop();
                }
                if(st.empty())
                ans.push_back(0);
                else ans.push_back(st.top());
                st.push(arr[i]);
            }
        }reverse(ans.begin(),ans.end());
        return ans;
    }
};