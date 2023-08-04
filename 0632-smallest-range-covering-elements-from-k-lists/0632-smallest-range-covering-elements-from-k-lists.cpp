class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int> ans(2);
        int n=nums.size();
        vector<priority_queue<int,vector<int>,greater<int>>> pq(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<nums[i].size();j++){
                pq[i].push(nums[i][j]);
            }
        }
        int len=INT_MAX;
        while(true){
            int mn=INT_MAX;
            int mx=INT_MIN;
            int remove=0;
            for(int i=0;i<n;i++){
                if(pq[i].empty())break;
                if(pq[i].top()<mn){
                    remove=i;
                    mn=pq[i].top();
                }
                mx=max(mx,pq[i].top());
            }
            if(mx-mn<len){
                len=mx-mn;
                ans[0]=mn;
                ans[1]=mx;
            }
            pq[remove].pop();
            if(pq[remove].empty())break;
        }return ans;
    }
};