class Solution {
public:
    bool dfs(int node,int parent,vector<vector<int>>& adj,vector<int> &vis){
        if(parent!=-1)vis[node]=!vis[parent];
        for(auto i:adj[node]){
            if(vis[i]==-1){
                if(dfs(i,node,adj,vis))return 1;
            }else if(vis[i]==vis[node]){
                return 1;
            }
        }return 0;
    }
    bool isBipartite(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<int> vis(n,-1);
        for(int i=0;i<n;i++){
            if(vis[i]==-1){
                if(dfs(i,-1,adj,vis))return false;
            }
        }return true;
    }
};