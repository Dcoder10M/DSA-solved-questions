class Solution {
public:
    int dfs(int node,vector<vector<int>> &adj,vector<int> &vis){
        vis[node]=1;
        int ans=0;
        for(auto i:adj[node]){
            if(!vis[i])
            ans+=dfs(i,adj,vis);
        }return 1+ans;
    }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<vector<int>> adj(n);\
        set<int> s;
        for(auto i:restricted)s.insert(i);
        for(auto i:edges){
            if(s.find(i[0])!=s.end() || s.find(i[1])!=s.end())continue;
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int> vis(n,0);
        return dfs(0,adj,vis);
    }
};