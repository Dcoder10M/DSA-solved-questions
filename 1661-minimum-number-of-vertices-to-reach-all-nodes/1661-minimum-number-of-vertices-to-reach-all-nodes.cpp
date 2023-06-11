class Solution {
public:
    // set<int> ans;
    // void dfs(int node,vector<vector<int>> &adj,vector<int> &vis){
    //     vis[node]=1;
    //     for(auto i:adj[node]){
    //         if(!vis[i]){
    //             dfs(i,adj,vis);
    //         }else{
    //             if(ans.find(i)!=ans.end())ans.erase(i);
    //         }
    //     }
    // }
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> res, visited(n);

        for (auto& e: edges)
            visited[e[1]] = 1;

        for (int i = 0; i < n; ++i)
            if (visited[i] == 0)
                res.push_back(i);
                
        return res;
    }
};