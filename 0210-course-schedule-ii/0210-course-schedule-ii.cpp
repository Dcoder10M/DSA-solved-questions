class Solution {
public:
    vector<int> findOrder(int A, vector<vector<int>>& pre) {
        vector<int> ans;
        vector<vector<int>> adj(A);
        vector<int> ind(A,0);
        queue<int> q;
        for(auto i:pre){
            adj[i[1]].push_back(i[0]);
            ind[i[0]]++;
        }
        for(int i=0;i<A;i++){
            if(ind[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto i:adj[node]){
                ind[i]--;
                if(ind[i]==0)q.push(i);
            }
        }
        if(ans.size()!=A)return {};
        return ans;
    }
};