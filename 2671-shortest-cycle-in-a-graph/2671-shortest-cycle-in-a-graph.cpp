class Solution {
private:
    void dfs(int src,int prnt,vector<int>&dis,int &ans,vector<int>adj[],int ini_dis,vector<int>&path_visited)
    {
        dis[src]=1+ini_dis;
        path_visited[src]=1;

        for(auto it:adj[src])
        {
            if(it!=prnt && path_visited[it]==1)
                 ans=min(ans,abs(dis[it]-dis[src]));
            else if(it!=prnt && path_visited[it]==0 && dis[src]+1<dis[it])
            {
                dfs(it,src,dis,ans,adj,dis[src],path_visited);
            }
        }
        path_visited[src]=0;
    }
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) 
    {
       
        vector<int>dis(n,1e9);
        vector<int>adj[n];
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
         int ans=INT_MAX;
         vector<int>path_visited(n,0);
        for(int i=0;i<n;i++)
        {
            if(dis[i]==1e9)
            {   
                
                dfs(i,-1,dis,ans,adj,-1,path_visited);
                cout<<ans<<endl;
            }
        }
        
        if(ans==INT_MAX) return -1;
        return ans+1;
    }
};