class Solution {
public:
    bool dfs(int node,vector<int> &vis,vector<vector<int>> &adj){
        for(auto i:adj[node]){
            if(!vis[i]){
                vis[i]=3-vis[node];
                if(!dfs(i,vis,adj))return false;
            }else{
                if(vis[i]==vis[node])return false;
            }
        }return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                vis[i]=1;
                if(!dfs(i,vis,graph))return false;
            }
        }return true;
    }
};