class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n=nums.size();
        int remove=n-k;
        if(k==0)return {};
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && st.top()>nums[i] && remove){
                remove--;
                st.pop();
            }
            st.push(nums[i]);
        }
        while(remove){
            st.pop();
            remove--;
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }reverse(ans.begin(),ans.end());
        return ans;
    }
};