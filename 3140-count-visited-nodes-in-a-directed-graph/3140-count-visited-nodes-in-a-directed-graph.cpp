class Solution {
public:
    vector<int> topo;
    vector<int> visited;
    vector<int> countVisitedNodes(vector<int>& edges) {
        // Run SCC algorithm
        int n = edges.size();
        visited = vector<int>(n);

        // Generate toposort
        for (int i = 0; i < n; ++i) {
            dfs(i, edges, visited);
        }

        // Generate transpose graph
        vector<vector<int>> transpose(n);
        for (int i = 0; i < n; ++i) {
            transpose[edges[i]].push_back(i);
        }
        vector<int> scc(n);
        int sccc = 0;
        visited = vector<int>(n);
        // Track which node belongs to which SCC
        for (int i = n-1; i >= 0; --i) {
            if (visited[topo[i]] == 0) {
                dfs2(topo[i], transpose, visited, scc, sccc);
                sccc++;
            }
        }


        // sccount tracks how many nodes each scc can see
        // sccadjlist is an adjlist where each node is an scc
        vector<int> ans(n);
        vector<vector<int>> sccadjlist(sccc);
        vector<int> sccount(sccc);
        for (int i = 0; i < n; ++i) {
            sccadjlist[scc[i]].push_back(i);
        }

        // For each scc, include the count of other scc it can 
        // reach
        for (int i = sccc - 1; i >= 0; --i) {
            sccount[i] = sccadjlist[i].size();
            for (auto node : sccadjlist[i]) {
                if (scc[edges[node]] != i) {
                    sccount[i] += sccount[scc[edges[node]]];
                }
            }
        }

        // For each node, update its count with the count of the 
        // SCC that it belongs to
        for (int i = 0; i < n; ++i) {
            ans[i] = sccount[scc[i]];
        }
        return ans;
    }
    
    void dfs(int i, vector<int>& edges, vector<int>& visited) {
        if (visited[i]) return;
        visited[i] = 1;
        dfs(edges[i], edges, visited);
        topo.push_back(i);
    }
    
    void dfs2(int i, vector<vector<int>>& edges, vector<int>& visited, vector<int>& scc, int sccc) {
        if (visited[i]) return;
        visited[i] = 1;
        scc[i] = sccc;
        for (auto neighbor : edges[i]) {
            dfs2(neighbor, edges, visited, scc, sccc);
        }
    }
};