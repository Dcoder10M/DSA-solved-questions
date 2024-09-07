class Solution {
public:
    vector<int> findOrder(int A, vector<vector<int>>& pre) {
        vector<int> ans;
        vector<vector<int>> adj(A);
        vector<int> dependent(A,0);
        for(int i=0;i<pre.size();i++){
            adj[pre[i][1]].push_back(pre[i][0]);
            dependent[pre[i][0]]++;
        }
        queue<int> q;
        for(int i=0;i<A;i++){
            if(dependent[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node=q.front();
            ans.push_back(node);
            q.pop();
            for(auto i:adj[node]){
                dependent[i]--;
                if(dependent[i]==0){
                    q.push(i);
                }
            }
        }
        if(ans.size()==A)
        return ans;
        return {};
    }
};