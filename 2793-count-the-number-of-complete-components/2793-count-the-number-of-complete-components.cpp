class Solution {
    void dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &nodes) {
        vis[node] = 1;
        nodes.push_back(node);
        for(int ad : adj[node]) {
            if(!vis[ad]) dfs(ad, adj, vis, nodes);
        }
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        vector<int> vis(n);
        int ans = 0;
        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                vector<int> nodes;
                dfs(i, adj, vis, nodes);
                int f = 1;
                
                for(int i : nodes) {
                    unordered_set<int> s(adj[i].begin(), adj[i].end());
                    for(int j : nodes) {
                        if(i == j) continue;
                        if(s.find(j) == s.end()) {
                            f = 0;
                            break;
                        }
                    }
                }  
                ans += f;
            } 
        }
        return ans;
    }
};