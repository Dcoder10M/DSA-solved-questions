class Solution {
public:
    vector<vector<int>> ans;
    vector<int> vis,ins,low;
    int timer;
    void solve(int node,int parent,
    vector<vector<int>> &adj){
        vis[node]=1;
        ins[node]=timer;
        low[node]=timer;
        timer++;
        for(auto i:adj[node]){
            if(parent==i)continue;
            if(!vis[i]){
                solve(i,node,adj);
                low[node]=min(low[node],low[i]);
                if(ins[node]<low[i]){
                    ans.push_back({i,node});
                }
            }else{
                low[node]=min(low[node],low[i]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vis.resize(n,0);
        ins.resize(n,0);
        low.resize(n,0);
    vector<vector<int>> adj(n);
        for(auto i:connections){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        timer=0;
        solve(0,-1,adj);
        return ans;
    }
};