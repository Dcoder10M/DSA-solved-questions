class Solution {
public:
    void dfs(int node,vector<vector<int>> &adj,vector<int> &vis,int &ans,map<vector<int>,int> &dp){
        vis[node]=1;
        for(auto i:adj[node]){
            if(!vis[i]){
                if(!dp[{i,node}])ans++;
                dfs(i,adj,vis,ans,dp);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& arr) {
        int ans=0;
        // int n=arr.size();
        vector<vector<int>> adj(n);
        map<vector<int>,int> dp;
        for(int i=0;i<arr.size();i++){
            adj[arr[i][0]].push_back(arr[i][1]);
            dp[{arr[i][0],arr[i][1]}]=1;
            adj[arr[i][1]].push_back(arr[i][0]);
        }
        vector<int> vis(n,0);

        dfs(0,adj,vis,ans,dp);
        return ans;
    }
};