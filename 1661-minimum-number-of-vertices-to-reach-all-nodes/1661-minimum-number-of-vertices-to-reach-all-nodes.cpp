class Solution {
public:
    set<int> ans;
    void dfs(int node,vector<vector<int>> &adj,vector<int> &vis){
        vis[node]=1;
        for(auto i:adj[node]){
            if(!vis[i]){
                dfs(i,adj,vis);
            }else{
                if(ans.find(i)!=ans.end())ans.erase(i);
            }
        }
    }
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        ans.clear();
        vector<int> vis(n,0);
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                ans.insert(i);
                dfs(i,adj,vis);
            }
        }
        vector<int> v;
        for(auto i:ans){
            v.push_back(i);
        }return v;
    }
};