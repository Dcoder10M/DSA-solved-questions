class Solution {

    void dfs(int node, unordered_map<int,int>&mp, int cnt, vector<int>adj[], vector<int>&vis, vector<int>&pathVis, int&ans,int st)
    {
        vis[node]=1;

        pathVis[node]=st;
      mp[node]= cnt;
    cnt++;
        for(auto it: adj[node])
        {
            if(!vis[it]){
                //cnt++;
                dfs(it, mp, cnt, adj, vis, pathVis, ans,st);
            }
            else if(pathVis[it]==st){
                
                //cout<<it<<endl;
                //cout<<mp[it]<<" "<<endl;
                ans= max(ans, cnt-mp[it] );
               
            }
        }
       // pathVis[node]=0;
    }

public:
    int longestCycle(vector<int>& edges) {
        int n= edges.size();
        vector<int> adj[n];

        for(int i=0; i<edges.size(); i++)
        {
            int u= i, v= edges[i];
            if(v==-1) continue;
            adj[u].push_back(v);
        }

        vector<int> vis(n+1, 0);
        vector<int> pathVis(n+1, 0);
        int ans=-1;
        for(int i=0; i<n; i++)
        {
            unordered_map<int,int> mp;
            int cnt=0;
            if(!vis[i]){
                int st=i;
                dfs(i, mp, cnt, adj, vis, pathVis, ans,st);
            }
        }
        return ans;
    }
};